typedef unsigned int u32;
typedef signed int s32;
extern u32 mainSegmentBssStart[];
extern u32 mainSegmentBssSize;
typedef unsigned long uintptr_t;

int main(void);

void entrypoint(void) {
    u32 *bss_ptr = mainSegmentBssStart;
    s32 remaining_size = (s32)(uintptr_t)&mainSegmentBssSize;

    while (remaining_size != 0) {
        remaining_size -= 8;
        bss_ptr[0] = 0;
        bss_ptr[1] = 0;
        bss_ptr += 2;
    }

    main();
}
