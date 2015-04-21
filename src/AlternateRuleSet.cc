#include "AlternateRuleSet.h"

bool AlternateRuleSet::mustMakeJumps(PLAYER player, bool is_king)
{
   //All players are forced to make jumps no matter what.
   
   return false;
}

bool AlternateRuleSet::canMoveBackwards(PLAYER player, bool is_king, bool is_jump)
{
   //Only king pieces can move backwards.
   
   return true;
}
