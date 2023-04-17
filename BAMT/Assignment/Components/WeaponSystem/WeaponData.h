#ifndef ASSIGNMENT_WEAPON_DATA
#define ASSIGNMENT_WEAPON_DATA
#include <string>

//							 NAME      | TYPE      | RATE   |     SPRITE PATH    | SIZE | SPEED | LIFE | KNOCK | SPREAD | DAMAGE
#define WEAPON_DATA_NONE    {"None"	   , basic     , 9999   , ""                 , 0    , 0     , 0    , 0     , 0      , 0}
#define WEAPON_DATA_PISTOL	{"Pistol"  , basic     , .3f    , "playerProj.png"   , .1f  , 20    , 2    , 10    , .02f   , 2}
#define WEAPON_DATA_RIFLE   {"Rifle"   , basic     , .08f   , "playerProj.png"   , .1f  , 15    , 2    , 5     , .05f   , 1}
#define WEAPON_DATA_SHOTGUN {"Shotgun" , multiShot , .5f    , "playerProj.png"   , .1f  , 10    , .5f  , 10    , .3f    , 1}
#define WEAPON_DATA_RANGER  {"Ranger"  , basic     , 2      , "enemyProj.png"    , .2f  , 3     , 5    , 3     , 0      , 1}
#define WEAPON_DATA_ZOMBIE  {"BRAINS..", basic     , 1      , "void.png"         , .1f  , 5     , .2f  , 0     , 0      , 1}
#define WEAPON_DATA_TANK    {"Tank"    , basic     , 3      , "enemyProj.png"    , .3f  , 2     , 5    , 10    , 0      , 5}


enum WeaponType{basic = 0, explosive = 1, multiShot = 2};

/// <summary>
/// Defines how a weapon and its projectiles act.
/// </summary>
struct WeaponData
{
	/// <summary>
	/// What Is this Weapon Called?
	/// </summary>
	std::string weaponName = "Default";

	/// <summary>
	/// What type of weapon is this?
	/// </summary>
	WeaponType type = basic;

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
	/// The lower the value, the more accurate the weapon will be.
	/// </summary>
	float projectileSpread = 0;

	/// <summary>
	/// How much damage the projectile will do.
	/// </summary>
	int projectileDamage = 1;
};
#endif