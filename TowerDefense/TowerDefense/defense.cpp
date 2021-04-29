#include "defense.h"

Defense::Defense()
{

}
Defense::Defense(AffinityType type, Point coords)
{
	Defense::affinity = type;
	Defense::posi = coords;
}