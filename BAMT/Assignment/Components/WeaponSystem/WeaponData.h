#ifndef ASSIGNMENT_WEAPON_DATA
#define ASSIGNMENT_WEAPON_DATA
#include <string>

#define WEAPON_DATA_PISTOL {.1f, "default.png", .2f, 10, 1, 1}
#define WEAPON_DATA_RIFLE {.5f, "default.png", .2f, 10, 1, 1}


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