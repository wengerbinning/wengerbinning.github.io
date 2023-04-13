GFP(Get Free Pages)



## 宏


```c
#define ___GFP_DMA		         0x01u
#define ___GFP_HIGHMEM		     0x02u
#define ___GFP_DMA32		     0x04u
#define ___GFP_MOVABLE		     0x08u
#define ___GFP_WAIT		         0x10u
#define ___GFP_HIGH		         0x20u
#define ___GFP_IO	    	     0x40u
#define ___GFP_FS		         0x80u
#define ___GFP_COLD		        0x100u
#define ___GFP_NOWARN		    0x200u
#define ___GFP_REPEAT		    0x400u
#define ___GFP_NOFAIL		    0x800u
#define ___GFP_NORETRY		   0x1000u
#define ___GFP_MEMALLOC		   0x2000u
#define ___GFP_COMP		       0x4000u
#define ___GFP_ZERO		       0x8000u
#define ___GFP_NOMEMALLOC	  0x10000u
#define ___GFP_HARDWALL		  0x20000u
#define ___GFP_THISNODE		  0x40000u
#define ___GFP_RECLAIMABLE	  0x80000u
#define ___GFP_KMEMCG		 0x100000u
#define ___GFP_NOTRACK		 0x200000u
#define ___GFP_NO_KSWAPD	 0x400000u
#define ___GFP_OTHER_NODE	 0x800000u
#define ___GFP_WRITE		0x1000000u
```

#### GFP_FLAGS

```c
#define GFP_NOWAIT	            (GFP_ATOMIC & ~__GFP_HIGH)
#define GFP_ATOMIC	            (__GFP_HIGH)
#define GFP_NOIO	            (__GFP_WAIT)
#define GFP_NOFS	            (__GFP_WAIT | __GFP_IO)
#define GFP_KERNEL	            (__GFP_WAIT | __GFP_IO | __GFP_FS)
#define GFP_TEMPORARY	        (__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_RECLAIMABLE)
#define GFP_USER	            (__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL)
#define GFP_HIGHUSER	        (__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL | __GFP_HIGHMEM)
#define GFP_HIGHUSER_MOVABLE	(__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL | __GFP_HIGHMEM | __GFP_MOVABLE)
#define GFP_IOFS	            (__GFP_IO | __GFP_FS)
#define GFP_TRANSHUGE	        (GFP_HIGHUSER_MOVABLE | __GFP_COMP | __GFP_NOMEMALLOC | __GFP_NORETRY | __GFP_NOWARN | __GFP_NO_KSWAPD)
```