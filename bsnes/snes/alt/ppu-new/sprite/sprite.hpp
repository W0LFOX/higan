class Sprite {
  struct Regs {
    unsigned priority0;
    unsigned priority1;
    unsigned priority2;
    unsigned priority3;

    unsigned base_size;
    unsigned nameselect;
    unsigned tiledata_addr;
    unsigned first_sprite;

    bool main_enable;
    bool sub_enable;

    bool interlace;

    bool time_over;
    bool range_over;
  } regs;

  struct List {
    unsigned width;
    unsigned height;
    unsigned x;
    unsigned y;
    unsigned character;
    bool use_nameselect;
    bool vflip;
    bool hflip;
    unsigned palette;
    unsigned priority;
    bool size;
  } list[128];

  uint8 itemlist[32];
  struct TileList {
    unsigned x;
    unsigned y;
    unsigned priority;
    unsigned palette;
    unsigned tile;
    bool hflip;
  } tilelist[34];

  struct Output {
    uint8 palette[256];
    uint8 priority[256];
  } output;

  void update_list(unsigned addr, uint8 data);
  void address_reset();
  void set_first();
  bool on_scanline(unsigned sprite);
  void render();
  Sprite(PPU &self);

  PPU &self;
  friend class PPU;
};
