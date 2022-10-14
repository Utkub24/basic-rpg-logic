#define LEVELUP \
            HP.setMax( HP.getMax() + (uint16_t)((BASEHP+1)/2.f) ); \
            HP.setVal(HP.getMax()); \
            incStats( (uint16_t)((BASESTR+1)/2.f), (uint16_t)((BASEINT+1)/2.f), (uint16_t)((BASEDEX+1)/2.f) )

#define SETHPANDSTATS \
HP.setMax(BASEHP);\
HP.setVal(BASEHP);\
setStats(BASESTR, BASEINT, BASEDEX)

#define BASESTATS_H \
static const uint16_t BASEHP;\
static const uint16_t BASESTR;\
static const uint16_t BASEINT;\
static const uint16_t BASEDEX
