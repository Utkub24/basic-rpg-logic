#define LEVELUP \
            HP.setMax( HP.getMax() + (uint16_t)((BASEHP+1)/2.f) ); \
            HP.setVal(HP.getMax()); \
            incStats( (uint16_t)((BASESTR+1)/2.f), (uint16_t)((BASEINT+1)/2.f), (uint16_t)((BASEDEX+1)/2.f) )
 

#define CHARACTERCLASS(classname, basehp, basestr, baseint, basedex) \
class classname : public Class { \
    public:\
        classname() \
            : Class(BASEHP) { \
                setStats(BASESTR, BASEINT, BASEDEX); \
            } \
        void levelUp() override { LEVELUP; }\
    private:\
        static const uint16_t BASEHP = basehp;\
        static const uint16_t BASESTR = basestr;\
        static const uint16_t BASEINT = baseint;\
        static const uint16_t BASEDEX = basedex;\
}

#define SETHPANDSTATS \
HP.setMax(BASEHP);\
HP.setVal(BASEHP);\
setStats(BASESTR, BASEINT, BASEDEX)

#define BASESTATS(basehp, basestr, baseint, basedex) \
static const uint16_t BASEHP = basehp;\
static const uint16_t BASESTR = basestr;\
static const uint16_t BASEINT = baseint;\
static const uint16_t BASEDEX = basedex
