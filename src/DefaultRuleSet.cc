#include "DefaultRuleSet.h"

bool DefaultRuleSet::mustMakeJumps(PLAYER player, bool is_king)
{
   //All players are forced to make jumps no matter what.
   
   return false;
}

bool DefaultRuleSet::canMoveBackwards(PLAYER player, bool is_king, bool is_jump)
{
   //Only king pieces can move backwards.
   
   return is_king;
}
