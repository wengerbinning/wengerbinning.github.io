

### dma-coherent.h


### dma-mapping-common.h

#### 预处理宏

* dma_map_single
* dma_unmap_single
* dma_map_sg
* dma_unmap_sg

* dma_get_sgtable

#### 模块依赖

* linux/kmemcheck.h
* linux/bug.h
* linux/scatterlist.h
* linux/dma-debug.h
* linux/dma-attrs.h
* asm-generic/dma-coherent.h

#### 函数接口

* dma_map_single_attrs
* dma_unmap_single_attrs
* dma_map_sg_attrs
* dma_unmap_sg_attrs
* dma_map_page
* dma_unmap_page

* dma_sync_single_for_cpu
* dma_sync_single_for_device
* dma_sync_single_range_for_cpu
* dma_sync_single_range_for_device
* dma_sync_sg_for_cpu
* dma_sync_sg_for_device

* dma_common_mmap
* dma_common_contiguous_remap
* dma_common_pages_remap
* dma_common_free_remap

* dma_alloc_attrs
* dma_free_attrs
* dma_free_coherent
* dma_alloc_noncoherent
* dma_free_noncoherent
* dma_mapping_error
* dma_alloc_nonconsistent
* dma_free_nonconsistent
* dma_mmap_nonconsistent

* dma_supported
* dma_set_mask
