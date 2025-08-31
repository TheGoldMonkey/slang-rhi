#pragma once

#include <slang-rhi.h>

#include "core/platform.h"

// #define WGPU_SKIP_DECLARATIONS
#include <webgpu/webgpu.h>
#include <webgpu/webgpu_enum_class_bitmasks.h>
// #include <webgpu/webgpu_cpp.h>

// clang-format off

#define SLANG_RHI_WGPU_PROCS(x) \
x(CreateInstance) \
x(GetInstanceFeatures) \
x(GetInstanceLimits) \
x(HasInstanceFeature) \
x(GetProcAddress) \
/*Methods of Adapter*/ \
x(AdapterGetFeatures) \
x(AdapterGetInfo) \
x(AdapterGetLimits) \
x(AdapterHasFeature) \
x(AdapterRequestDevice) \
x(AdapterAddRef) \
x(AdapterRelease) \
/*Methods of AdapterInfo*/ \
x(AdapterInfoFreeMembers) \
/*Methods of BindGroup*/ \
x(BindGroupSetLabel) \
x(BindGroupAddRef) \
x(BindGroupRelease) \
/*Methods of BindGroupLayout*/ \
x(BindGroupLayoutSetLabel) \
x(BindGroupLayoutAddRef) \
x(BindGroupLayoutRelease) \
/*Methods of Buffer*/ \
x(BufferDestroy) \
x(BufferGetConstMappedRange) \
x(BufferGetMappedRange) \
x(BufferGetMapState) \
x(BufferGetSize) \
x(BufferGetUsage) \
x(BufferMapAsync) \
x(BufferReadMappedRange) \
x(BufferSetLabel) \
x(BufferUnmap) \
x(BufferWriteMappedRange) \
x(BufferAddRef) \
x(BufferRelease) \
/*Methods of CommandBuffer*/ \
x(CommandBufferSetLabel) \
x(CommandBufferAddRef) \
x(CommandBufferRelease) \
/*Methods of CommandEncoder*/ \
x(CommandEncoderBeginComputePass) \
x(CommandEncoderBeginRenderPass) \
x(CommandEncoderClearBuffer) \
x(CommandEncoderCopyBufferToBuffer) \
x(CommandEncoderCopyBufferToTexture) \
x(CommandEncoderCopyTextureToBuffer) \
x(CommandEncoderCopyTextureToTexture) \
x(CommandEncoderFinish) \
x(CommandEncoderInsertDebugMarker) \
x(CommandEncoderPopDebugGroup) \
x(CommandEncoderPushDebugGroup) \
x(CommandEncoderResolveQuerySet) \
x(CommandEncoderSetLabel) \
x(CommandEncoderWriteTimestamp) \
x(CommandEncoderAddRef) \
x(CommandEncoderRelease) \
/*Methods of ComputePassEncoder*/ \
x(ComputePassEncoderDispatchWorkgroups) \
x(ComputePassEncoderDispatchWorkgroupsIndirect) \
x(ComputePassEncoderEnd) \
x(ComputePassEncoderInsertDebugMarker) \
x(ComputePassEncoderPopDebugGroup) \
x(ComputePassEncoderPushDebugGroup) \
x(ComputePassEncoderSetBindGroup) \
x(ComputePassEncoderSetLabel) \
x(ComputePassEncoderSetPipeline) \
x(ComputePassEncoderWriteTimestamp) \
x(ComputePassEncoderAddRef) \
x(ComputePassEncoderRelease) \
/*Methods of ComputePipeline*/ \
x(ComputePipelineGetBindGroupLayout) \
x(ComputePipelineSetLabel) \
x(ComputePipelineAddRef) \
x(ComputePipelineRelease) \
/*Methods of Device*/ \
x(DeviceCreateBindGroup) \
x(DeviceCreateBindGroupLayout) \
x(DeviceCreateBuffer) \
x(DeviceCreateCommandEncoder) \
x(DeviceCreateComputePipeline) \
x(DeviceCreateComputePipelineAsync) \
x(DeviceCreatePipelineLayout) \
x(DeviceCreateQuerySet) \
x(DeviceCreateRenderBundleEncoder) \
x(DeviceCreateRenderPipeline) \
x(DeviceCreateRenderPipelineAsync) \
x(DeviceCreateSampler) \
x(DeviceCreateShaderModule) \
x(DeviceCreateTexture) \
x(DeviceDestroy) \
x(DeviceGetAdapterInfo) \
x(DeviceGetFeatures) \
x(DeviceGetLimits) \
x(DeviceGetLostFuture) \
x(DeviceGetQueue) \
x(DeviceHasFeature) \
x(DevicePopErrorScope) \
x(DevicePushErrorScope) \
x(DeviceSetLabel) \
x(DeviceAddRef) \
x(DeviceRelease) \
/*Methods of Instance*/ \
x(InstanceCreateSurface) \
x(InstanceGetWGSLLanguageFeatures) \
x(InstanceHasWGSLLanguageFeature) \
x(InstanceProcessEvents) \
x(InstanceRequestAdapter) \
x(InstanceWaitAny) \
x(InstanceAddRef) \
x(InstanceRelease) \
/*Methods of PipelineLayout*/ \
x(PipelineLayoutSetLabel) \
x(PipelineLayoutAddRef) \
x(PipelineLayoutRelease) \
/*Methods of QuerySet*/ \
x(QuerySetDestroy) \
x(QuerySetGetCount) \
x(QuerySetGetType) \
x(QuerySetSetLabel) \
x(QuerySetAddRef) \
x(QuerySetRelease) \
/*Methods of Queue*/ \
x(QueueOnSubmittedWorkDone) \
x(QueueSetLabel) \
x(QueueSubmit) \
x(QueueWriteBuffer) \
x(QueueWriteTexture) \
x(QueueAddRef) \
x(QueueRelease) \
/*Methods of RenderBundle*/ \
x(RenderBundleSetLabel) \
x(RenderBundleAddRef) \
x(RenderBundleRelease) \
/*Methods of RenderBundleEncoder*/ \
x(RenderBundleEncoderDraw) \
x(RenderBundleEncoderDrawIndexed) \
x(RenderBundleEncoderDrawIndexedIndirect) \
x(RenderBundleEncoderDrawIndirect) \
x(RenderBundleEncoderFinish) \
x(RenderBundleEncoderInsertDebugMarker) \
x(RenderBundleEncoderPopDebugGroup) \
x(RenderBundleEncoderPushDebugGroup) \
x(RenderBundleEncoderSetBindGroup) \
x(RenderBundleEncoderSetIndexBuffer) \
x(RenderBundleEncoderSetLabel) \
x(RenderBundleEncoderSetPipeline) \
x(RenderBundleEncoderSetVertexBuffer) \
x(RenderBundleEncoderAddRef) \
x(RenderBundleEncoderRelease) \
/*Methods of RenderPassEncoder*/ \
x(RenderPassEncoderBeginOcclusionQuery) \
x(RenderPassEncoderDraw) \
x(RenderPassEncoderDrawIndexed) \
x(RenderPassEncoderDrawIndexedIndirect) \
x(RenderPassEncoderDrawIndirect) \
x(RenderPassEncoderEnd) \
x(RenderPassEncoderEndOcclusionQuery) \
x(RenderPassEncoderExecuteBundles) \
x(RenderPassEncoderInsertDebugMarker) \
x(RenderPassEncoderMultiDrawIndexedIndirect) \
x(RenderPassEncoderMultiDrawIndirect) \
x(RenderPassEncoderPopDebugGroup) \
x(RenderPassEncoderPushDebugGroup) \
x(RenderPassEncoderSetBindGroup) \
x(RenderPassEncoderSetBlendConstant) \
x(RenderPassEncoderSetIndexBuffer) \
x(RenderPassEncoderSetLabel) \
x(RenderPassEncoderSetPipeline) \
x(RenderPassEncoderSetScissorRect) \
x(RenderPassEncoderSetStencilReference) \
x(RenderPassEncoderSetVertexBuffer) \
x(RenderPassEncoderSetViewport) \
x(RenderPassEncoderWriteTimestamp) \
x(RenderPassEncoderAddRef) \
x(RenderPassEncoderRelease) \
/*Methods of RenderPipeline*/ \
x(RenderPipelineGetBindGroupLayout) \
x(RenderPipelineSetLabel) \
x(RenderPipelineAddRef) \
x(RenderPipelineRelease) \
/*Methods of Sampler*/ \
x(SamplerSetLabel) \
x(SamplerAddRef) \
x(SamplerRelease) \
/*Methods of ShaderModule*/ \
x(ShaderModuleGetCompilationInfo) \
x(ShaderModuleSetLabel) \
x(ShaderModuleAddRef) \
x(ShaderModuleRelease) \
/*Methods of SupportedFeatures*/ \
x(SupportedFeaturesFreeMembers) \
/*Methods of SupportedInstanceFeatures*/ \
x(SupportedInstanceFeaturesFreeMembers) \
/*Methods of SupportedWGSLLanguageFeatures*/ \
x(SupportedWGSLLanguageFeaturesFreeMembers) \
/*Methods of Surface*/ \
x(SurfaceConfigure) \
x(SurfaceGetCapabilities) \
x(SurfaceGetCurrentTexture) \
x(SurfacePresent) \
x(SurfaceSetLabel) \
x(SurfaceUnconfigure) \
x(SurfaceAddRef) \
x(SurfaceRelease) \
/*Methods of SurfaceCapabilities*/ \
x(SurfaceCapabilitiesFreeMembers) \
/*Methods of Texture*/ \
x(TextureCreateView) \
x(TextureDestroy) \
x(TextureGetDepthOrArrayLayers) \
x(TextureGetDimension) \
x(TextureGetFormat) \
x(TextureGetHeight) \
x(TextureGetMipLevelCount) \
x(TextureGetSampleCount) \
x(TextureGetUsage) \
x(TextureGetWidth) \
x(TextureSetLabel) \
x(TextureAddRef) \
x(TextureRelease) \
/*Methods of TextureView*/ \
x(TextureViewSetLabel) \
x(TextureViewAddRef) \
x(TextureViewRelease) \

// clang-format on

namespace rhi::wgpu {

struct API
{
    SharedLibraryHandle m_module = nullptr;

    ~API();

    Result init();

#define WGPU_DECLARE_PROC(name) WGPUProc##name wgpu##name = ::wgpu##name;
    SLANG_RHI_WGPU_PROCS(WGPU_DECLARE_PROC)
#undef WGPU_DECLARE_PROC
};

} // namespace rhi::wgpu
