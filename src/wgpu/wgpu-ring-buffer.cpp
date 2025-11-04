// #include "wgpu-base.h"
// #include "wgpu-device.h"
// #include <memory>
// #include <vector>

// namespace rhi::wgpu {

// class AutoRingBuffer {
// public:
//     AutoRingBuffer(DeviceImpl* device, uint32_t chunkSize)
//         : m_device(device), m_chunkSize(chunkSize) {
//         m_queue = device->m_queue;
//     }

//     ~AutoRingBuffer() {
//         for (auto& chunk : m_availChunks) {
//             chunk->destroy();
//         }
//         m_availChunks.clear();
//     }

//     void uploadBufferData(WGPUBuffer destBuffer, uint64_t destOffset, const void* src, uint64_t size) {
//         if (!m_availChunks.empty()) {
//             auto& chunk = m_availChunks.front();
//             if (chunk->push(destBuffer, destOffset, src, size)) {
//                 return;
//             }
//             chunk->flush();
//             m_availChunks.erase(m_availChunks.begin());
//         }

//         while (m_chunkSize < size) {
//             m_chunkSize *= 2;
//         }

//         auto newChunk = std::make_unique<Chunk>(this, m_chunkSize);
//         newChunk->push(destBuffer, destOffset, src, size);
//         m_availChunks.push_back(std::move(newChunk));
//     }

//     void flush() {
//         if (!m_availChunks.empty()) {
//             m_availChunks.front()->flush();
//             m_availChunks.erase(m_availChunks.begin());
//         }
//     }

//     void destroy() {
//         for (auto& chunk : m_availChunks) {
//             chunk->destroy();
//         }
//         m_availChunks.clear();
//     }

// private:
//     struct Chunk {
//         AutoRingBuffer* m_parent;
//         WGPUBuffer m_buffer;
//         uint32_t m_size;
//         uint8_t* m_mapTyped;
//         uint32_t m_pos;
//         WGPUCommandEncoder m_enc;

//         Chunk(AutoRingBuffer* parent, uint32_t size)
//             : m_parent(parent), m_size(size), m_mapTyped(nullptr), m_pos(0) {
//             WGPUBufferDescriptor desc = {};
//             desc.size = size;
//             desc.usage = WGPUBufferUsage_MapWrite | WGPUBufferUsage_CopySrc;
//             desc.mappedAtCreation = true;
//             m_buffer = wgpuDeviceCreateBuffer(parent->m_device->m_ctx.device, &desc);
//             void* initialMap = wgpuBufferGetMappedRange(m_buffer, 0, size);
//             reset(initialMap);
//         }

//         void reset(void* mappedArrayBuffer) {
//             m_mapTyped = static_cast<uint8_t*>(mappedArrayBuffer);
//             m_pos = 0;
//             WGPUCommandEncoderDescriptor encDesc = {};
//             m_enc = wgpuDeviceCreateCommandEncoder(m_parent->m_device->m_ctx.device, &encDesc);
//         }

//         bool push(WGPUBuffer destBuffer, uint64_t destOffset, const void* src, uint64_t byteCount) {
//             const uint64_t end = m_pos + byteCount;
//             if (end > m_size)
//                 return false;
//             memcpy(m_mapTyped + m_pos, src, byteCount);
//             wgpuCommandEncoderCopyBufferToBuffer(m_enc, m_buffer, m_pos, destBuffer, destOffset, byteCount);
//             m_pos = end;
//             return true;
//         }

//         void flush() {
//             wgpuBufferUnmap(m_buffer);
//             WGPUCommandBufferDescriptor cbDesc = {};
//             WGPUCommandBuffer cb = wgpuCommandEncoderFinish(m_enc, &cbDesc);
//             wgpuQueueSubmit(m_parent->m_queue, 1, &cb);
//             wgpuBufferMapAsync(m_buffer, WGPUMapMode_Write, 0, m_size,
//                 [](WGPUMapAsyncStatus status, void* userdata) {
//                     if (status == WGPUMapAsyncStatus_Success) {
//                         Chunk* self = static_cast<Chunk*>(userdata);
//                         void* newMap = wgpuBufferGetMappedRange(self->m_buffer, 0, self->m_size);
//                         self->reset(newMap);
//                     }
//                 }, this);
//         }

//         void destroy() {
//             wgpuBufferDestroy(m_buffer);
//         }
//     };

//     DeviceImpl* m_device;
//     RefPtr<CommandQueueImpl> m_queue;
//     uint32_t m_chunkSize;
//     std::vector<std::unique_ptr<Chunk>> m_availChunks;
// };

// }

// // function AutoRingBuffer(device, chunkSize) {
// //     const queue = device.defaultQueue;
// //     let availChunks = [];

// //     function Chunk() {
// //         const size = chunkSize;
// //         const [buf, initialMap] = this.device.createBufferMapped({
// //             size: size,
// //             usage: GPUBufferUsage.MAP_WRITE | GPUBufferUsage.COPY_SRC,
// //         });

// //         let mapTyped;
// //         let pos;
// //         let enc;
// //         this.reset = function(mappedArrayBuffer) {
// //             mapTyped = new Uint8Array(mappedArrayBuffer);
// //             pos = 0;
// //             enc = device.createCommandEncoder({});
// //             if (size == chunkSize) {
// //                 availChunks.push(this);
// //             }
// //         };
// //         this.reset(initialMap);

// //         this.push = function(destBuffer, destOffset, srcArrayBuffer) {
// //             const byteCount = srcArrayBuffer.byteLength;
// //             const end = pos + byteCount;
// //             if (end > size)
// //                 return false;
// //             mapTyped.set(new Uint8Array(srcArrayBuffer), pos);
// //             enc.copyBufferToBuffer(buf, pos, destBuffer, destOffset, byteCount);
// //             pos = end;
// //             return true;
// //         };

// //         this.flush = async function() {
// //             const cb = enc.finish();
// //             queue.submit([cb]);
// //             const newMap = await buf.mapWriteAsync();
// //             this.reset(newMap);
// //         };

// //         this.destroy = function() {
// //             buf.destroy();
// //         };
// //     };

// //     this.upload_buffer_data = function(destBuffer, destOffset, srcArrayBuffer) {
// //         if (availChunks.length) {
// //             const chunk = availChunks[0];
// //             if (chunk.push(destBuffer, destOffset, srcArrayBuffer))
// //                 return;
// //             chunk.flush();
// //             this.destroy();

// //             while (true) {
// //                 chunkSize *= 2;
// //                 if (chunkSize >= srcArrayBuffer.byteLength)
// //                     break;
// //             }
// //         }

// //         new Chunk();
// //         availChunks[0].push(destBuffer, destOffset, srcArrayBuffer);
// //     };

// //     this.flush = function() {
// //         if (availChunks.length) {
// //             availChunks[0].flush();
// //             availChunks.shift();
// //         }
// //     };

// //     this.destroy = function() {
// //         availChunks.forEach(x => x.destroy());
// //         availChunks = [];
// //     };
// // };