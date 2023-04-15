#ifndef ASSIGNMENT_WEAPON_DATA
#define ASSIGNMENT_WEAPON_DATA
#include <string>

//							 RATE   |     SPRITE PATH    | SIZE | SPEED | LIFE | KNOCK | DAMAGE
#define WEAPON_DATA_NONE    {9999   , ""                 , 0    , 0     , 0    , 0     , 0}
#define WEAPON_DATA_PISTOL	{.1f    , "default.png"      , .1f  , 10    , 2    , 10    , 1}
#define WEAPON_DATA_RIFLE   {.08f   , "default.png"      , .1f  , 15    , 2    , 5     , 1}
#define WEAPON_DATA_RANGER  {2      , "default.png"      , .2f  , 5     , 5    , 5     , 1}
#define WEAPON_DATA_ZOMBIE  {1      , "default.png"      , .1f  , 5     , .2f  , 1     , 1}
#define WEAPON_DATA_TANK    {3      , "default.png"      , .3f  , 5     , 5    , 20    , 5}


/// <summary>
/// Defines how a weapon and its projectiles act.
/// </summary>
struct WeaponData
{
	/// <summary>
	/// How fast the weapon fires in seconds.
	/// </summary>
	float fireRate = 1;

	/// <summary>
	/// The Sprite the projectile will use.
	/// </summary>
	std::string projectileSprite = "default.png";

	/// <summary>
	/// How big the projectile will be.
	/// </summary>
	float projectileSize = 1;

	/// <summary>
	/// How fast the projectile will be when fired.
	/// </summary>
	float projectileSpeed = 1;

	/// <summary>
	/// How long will the projectile exist within the level before it is disabled.
	/// </summary>
	float projectileLifeTime = 1;

	/// <summary>
	/// The amount of knock-back the projectile will apply on
	///	whoever it hit.
	/// </summary>
	float projectileKnockback = 1;

	/// <summary>
	/// How much damage the projectile will do.
	/// </summary>
	int projectileDamage = 1;
};
#endif