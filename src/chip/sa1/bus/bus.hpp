struct SA1Bus : Bus {
  void init();
};

struct VectorSelectionPage : Memory {
  alwaysinline uint8_t read(unsigned);
  alwaysinline void write(unsigned, uint8_t);
  void sync();
  Memory *access;
};

struct CC1BWRAM : Memory {
  unsigned size() const;
  alwaysinline uint8_t read(unsigned);
  alwaysinline void write(unsigned, uint8_t);
  bool dma;
};

struct BitmapRAM : Memory {
  unsigned size() const;
  alwaysinline uint8_t read(unsigned);
  alwaysinline void write(unsigned, uint8_t);
};

namespace memory {
  extern VectorSelectionPage vectorsp;
  extern StaticRAM iram;
  extern MappedRAM &bwram;
  extern CC1BWRAM cc1bwram;
  extern BitmapRAM bitmapram;
}