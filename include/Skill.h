#ifndef SKILL_H
#define SKILL_H
#include<Sky.h>

class Skill
{
    public:
        Skill(Sky *Sky);
        virtual ~Skill();
        void boom();
    protected:
    private:
        Sky *ownSky;
};

#endif // SKILL_H
