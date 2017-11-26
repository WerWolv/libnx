#include <string.h>
#include <switch.h>

typedef struct {
    u8  payload[0x400];
    u32 capacity;
    u32 size;
    u32 read_pos;

    u8 *ParcelObjects;
    u32 ParcelObjectsSize;
} Parcel;

void parcelInitialize(Parcel *ctx);
Result parcelTransact(binderSession *session, u32 code, Parcel *in_parcel, Parcel *reply_parcel);

void* parcelWriteData(Parcel *ctx, void* data, size_t data_size);
void* parcelReadData(Parcel *ctx, void* data, size_t data_size);

void parcelWriteInt32(Parcel *ctx, s32 val);
void parcelWriteUInt32(Parcel *ctx, u32 val);
void parcelWriteString16(Parcel *ctx, const char *str);
void parcelWriteInterfaceToken(Parcel *ctx, const char *interface);

s32 parcelReadInt32(Parcel *ctx);
u32 parcelReadUInt32(Parcel *ctx);
