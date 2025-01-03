#pragma once
#include <types.h>

constexpr int hotdogStandHash = 0xA1BC2F96;		//prop_hotdogstand_01
constexpr int burgerStandHash = 0x434BFB7C;		//prop_burgerstand_01
constexpr int LChotdogStandHash1 = 0x1F5BA936;  //gb_hotdogstand01
constexpr int LChotdogStandHash2 = 0x7221CEBD;  //gb_hotdogstand02
constexpr int LChotdogStandHash3 = 0x43EA7253;  //gb_hotdogstand03
constexpr int LChotdogStandHash4 = 0x16BA97F4;  //gb_hotdogstand04
constexpr int S_M_M_StrVend_01 = 0xCE9113A9;	//S_M_M_StrVend_01
constexpr int S_M_Y_StrVend_01 = 0x927F2323;	//S_M_Y_StrVend_01
constexpr int A_M_Y_GenStreet_01 = 0x9877EF71;	//A_M_Y_GenStreet_01
constexpr int A_M_Y_GenStreet_02 = 0x3521A8D2;	//A_M_Y_GenStreet_02
constexpr int A_M_Y_Downtown_01 = 0x2DADF4AA;	//A_M_Y_Downtown_01
constexpr int A_M_Y_Latino_01 = 0x132C1A8E;		//A_M_Y_Latino_01
constexpr int hotdogHash = 0x98EE1ACD;			//prop_cs_hotdog_01
constexpr int eatenHotdogHash = 0xA7303751;		//prop_cs_hotdog_02
constexpr int burgerHash = 0x858BB1D0;			//prop_cs_burger_01
constexpr int MichaelPed = 0xD7114C9;			//Player_Zero
constexpr int FranklinPed = 0x9B22DBAF;			//Player_One
constexpr int TrevorPed = 0x9B810FA2;			//Player_Two
constexpr int SP0_TOTAL_CASH = 0x324C31D;		//SP0_TOTAL_CASH
constexpr int SP1_TOTAL_CASH = 0x44BD6982;		//SP1_TOTAL_CASH
constexpr int SP2_TOTAL_CASH = 0x8D75047D;		//SP2_TOTAL_CASH
constexpr int WEAPON_UNARMED = 0xA2719263;		//WEAPON_UNARMED

//Tasks
constexpr int SCRIPT_TASK_GO_STRAIGHT_TO_COORD = 0x7D8F4411;	//joaat(SCRIPT_TASK_GO_STRAIGHT_TO_COORD)

//Ped move blend ratios
constexpr float PEDMOVEBLENDRATIO_STILL = 0.0f;
constexpr float PEDMOVEBLENDRATIO_WALK = 1.0f;
constexpr float PEDMOVEBLENDRATIO_RUN = 2.0f;
constexpr float PEDMOVEBLENDRATIO_SPRINT = 3.0f;

//HUD enums
constexpr int NEW_HUD_CASH = 3;

class Timer {
	int gameTimer = 0;
public:
	void Set(int value);
	int Get();
};

void PrintHelp(char* string, bool playSound, int overrideDuration = -1);
Object GetVendorStand(Vector3 pedLoc, float radious);
int GetStandType(Object stand);
bool IsPedVendor(Ped ped);
bool FindVendor(Object vendorStand, Ped* vendor);
bool RequestAnimDict(char* animDict);
bool RequestModel(Hash model);
Object CreateObject(Hash model, Vector3 loc = { NULL, NULL, NULL, NULL, NULL, NULL }, float rotX = NULL, float rotY = NULL, float rotZ = NULL);
void DeleteObject(Object obj);
int GetPlayerCash(Ped playerPed);
void SetPlayerCash(Ped playerPed, int currentCash, int change);
void UpdateCashHUD();
bool PrintVendorMessage(int playerCash, int standType);
bool AdditionalChecks(Ped ped);
void DisablePlayerActionsThisFrame();
void DisablePlayerControlThisFrame();
void PlayAmbientSpeech(Ped ped, char* speechName);

enum eEatSequences
{
	HOTDOG,
	BURGER
};

enum PedFlag {
	//Ped Config Flags
	PCF_PhoneDisableTextingAnimations = 242,
	PCF_PhoneDisableTalkingAnimations = 243,
	PCF_PhoneDisableCameraAnimations = 244,
	PCF_DisableShockingEvents = 294,
	PCF_DisableTalkTo = 329,

	//Ped Reset Flags
	PRF_DisablePlayerJumping = 46,
	PRF_DisablePlayerVaulting = 47,
	PRF_DisableSecondaryAnimationTasks = 58
};

enum eAnimationFlag
{
	AF_DEFAULT = 0,
	AF_LOOPING = 1,
	AF_HOLD_LAST_FRAME = 2,
	AF_REPOSITION_WHEN_FINISHED = 4,
	AF_NOT_INTERRUPTABLE = 8,
	AF_UPPERBODY = 16,
	AF_SECONDARY = 32,
	AF_REORIENT_WHEN_FINISHED = 64,
	AF_ABORT_ON_PED_MOVEMENT = 128,
	AF_ADDITIVE = 256,
	AF_TURN_OFF_COLLISION = 512,
	AF_OVERRIDE_PHYSICS = 1024,
	AF_IGNORE_GRAVITY = 2048,
	AF_EXTRACT_INITIAL_OFFSET = 4096,
	AF_EXIT_AFTER_INTERRUPTED = 8192,
	AF_TAG_SYNC_IN = 16384,
	AF_TAG_SYNC_OUT = 32768,
	AF_TAG_SYNC_CONTINUOUS = 65536,
	AF_FORCE_START = 131072,
	AF_USE_KINEMATIC_PHYSICS = 262144,
	AF_USE_MOVER_EXTRACTION = 524288,
	AF_HIDE_WEAPON = 1048576,
	AF_ENDS_IN_DEAD_POSE = 2097152,
	AF_ACTIVATE_RAGDOLL_ON_COLLISION = 4194304,
	AF_DONT_EXIT_ON_DEATH = 8388608,
	AF_ABORT_ON_WEAPON_DAMAGE = 16777216,
	AF_DISABLE_FORCED_PHYSICS_UPDATE = 33554432,
	AF_PROCESS_ATTACHMENTS_ON_START = 67108864,
	AF_EXPAND_PED_CAPSULE_FROM_SKELETON = 134217728,
	AF_USE_ALTERNATIVE_FP_ANIM = 268435456,
	AF_BLENDOUT_WRT_LAST_FRAME = 536870912,
	AF_USE_FULL_BLENDING = 1073741824
};

constexpr int defaultAF = AF_NOT_INTERRUPTABLE | AF_TAG_SYNC_IN | AF_TAG_SYNC_OUT | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE;
constexpr int upperAF = AF_NOT_INTERRUPTABLE | AF_UPPERBODY | AF_TAG_SYNC_IN | AF_TAG_SYNC_OUT | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE;
constexpr int upperSecondaryAF = AF_NOT_INTERRUPTABLE | AF_UPPERBODY | AF_SECONDARY | AF_HIDE_WEAPON | AF_ABORT_ON_WEAPON_DAMAGE;

enum eScriptLookFlag
{
	SLF_DEFAULT = 0,
	SLF_SLOW_TURN_RATE = 1,
	SLF_FAST_TURN_RATE = 2,
	SLF_EXTEND_YAW_LIMIT = 4,
	SLF_EXTEND_PITCH_LIMIT = 8,
	SLF_WIDEST_YAW_LIMIT = 16,
	SLF_WIDEST_PITCH_LIMIT = 32,
	SLF_NARROW_YAW_LIMIT = 64,
	SLF_NARROW_PITCH_LIMIT = 128,
	SLF_NARROWEST_YAW_LIMIT = 256,
	SLF_NARROWEST_PITCH_LIMIT = 512,
	SLF_USE_TORSO = 1024,
	SLF_WHILE_NOT_IN_FOV = 2048,
	SLF_USE_CAMERA_FOCUS = 4096,
	SLF_USE_EYES_ONLY = 8192,
	SLF_USE_LOOK_DIR = 16384,
	SLF_FROM_SCRIPT = 32768,
	SLF_USE_REF_DIR_ABSOLUTE = 65536
};

constexpr int PLAYER_CONTROL = 0;
constexpr int FRONTEND_CONTROL = 2;

enum eControlAction
{
	INPUT_NEXT_CAMERA = 0,
	INPUT_LOOK_LR,
	INPUT_LOOK_UD,
	INPUT_LOOK_UP_ONLY,
	INPUT_LOOK_DOWN_ONLY,
	INPUT_LOOK_LEFT_ONLY,
	INPUT_LOOK_RIGHT_ONLY,
	INPUT_CINEMATIC_SLOWMO,
	INPUT_SCRIPTED_FLY_UD,
	INPUT_SCRIPTED_FLY_LR,
	INPUT_SCRIPTED_FLY_ZUP,
	INPUT_SCRIPTED_FLY_ZDOWN,
	INPUT_WEAPON_WHEEL_UD,
	INPUT_WEAPON_WHEEL_LR,
	INPUT_WEAPON_WHEEL_NEXT,
	INPUT_WEAPON_WHEEL_PREV,
	INPUT_SELECT_NEXT_WEAPON,
	INPUT_SELECT_PREV_WEAPON,
	INPUT_SKIP_CUTSCENE,
	INPUT_CHARACTER_WHEEL,
	INPUT_MULTIPLAYER_INFO,
	INPUT_SPRINT,
	INPUT_JUMP,
	INPUT_ENTER,
	INPUT_ATTACK,
	INPUT_AIM,
	INPUT_LOOK_BEHIND,
	INPUT_PHONE,
	INPUT_SPECIAL_ABILITY,
	INPUT_SPECIAL_ABILITY_SECONDARY,
	INPUT_MOVE_LR,
	INPUT_MOVE_UD,
	INPUT_MOVE_UP_ONLY,
	INPUT_MOVE_DOWN_ONLY,
	INPUT_MOVE_LEFT_ONLY,
	INPUT_MOVE_RIGHT_ONLY,
	INPUT_DUCK,
	INPUT_SELECT_WEAPON,
	INPUT_PICKUP,
	INPUT_SNIPER_ZOOM,
	INPUT_SNIPER_ZOOM_IN_ONLY,
	INPUT_SNIPER_ZOOM_OUT_ONLY,
	INPUT_SNIPER_ZOOM_IN_SECONDARY,
	INPUT_SNIPER_ZOOM_OUT_SECONDARY,
	INPUT_COVER,
	INPUT_RELOAD,
	INPUT_TALK,
	INPUT_DETONATE,
	INPUT_HUD_SPECIAL,
	INPUT_ARREST,
	INPUT_ACCURATE_AIM,
	INPUT_CONTEXT,
	INPUT_CONTEXT_SECONDARY,
	INPUT_WEAPON_SPECIAL,
	INPUT_WEAPON_SPECIAL_TWO,
	INPUT_DIVE,
	INPUT_DROP_WEAPON,
	INPUT_DROP_AMMO,
	INPUT_THROW_GRENADE,
	INPUT_VEH_MOVE_LR,
	INPUT_VEH_MOVE_UD,
	INPUT_VEH_MOVE_UP_ONLY,
	INPUT_VEH_MOVE_DOWN_ONLY,
	INPUT_VEH_MOVE_LEFT_ONLY,
	INPUT_VEH_MOVE_RIGHT_ONLY,
	INPUT_VEH_SPECIAL,
	INPUT_VEH_GUN_LR,
	INPUT_VEH_GUN_UD,
	INPUT_VEH_AIM,
	INPUT_VEH_ATTACK,
	INPUT_VEH_ATTACK2,
	INPUT_VEH_ACCELERATE,
	INPUT_VEH_BRAKE,
	INPUT_VEH_DUCK,
	INPUT_VEH_HEADLIGHT,
	INPUT_VEH_EXIT,
	INPUT_VEH_HANDBRAKE,
	INPUT_VEH_HOTWIRE_LEFT,
	INPUT_VEH_HOTWIRE_RIGHT,
	INPUT_VEH_LOOK_BEHIND,
	INPUT_VEH_CIN_CAM,
	INPUT_VEH_NEXT_RADIO,
	INPUT_VEH_PREV_RADIO,
	INPUT_VEH_NEXT_RADIO_TRACK,
	INPUT_VEH_PREV_RADIO_TRACK,
	INPUT_VEH_RADIO_WHEEL,
	INPUT_VEH_HORN,
	INPUT_VEH_FLY_THROTTLE_UP,
	INPUT_VEH_FLY_THROTTLE_DOWN,
	INPUT_VEH_FLY_YAW_LEFT,
	INPUT_VEH_FLY_YAW_RIGHT,
	INPUT_VEH_PASSENGER_AIM,
	INPUT_VEH_PASSENGER_ATTACK,
	INPUT_VEH_SPECIAL_ABILITY_FRANKLIN,
	INPUT_VEH_STUNT_UD,
	INPUT_VEH_CINEMATIC_UD,
	INPUT_VEH_CINEMATIC_UP_ONLY,
	INPUT_VEH_CINEMATIC_DOWN_ONLY,
	INPUT_VEH_CINEMATIC_LR,
	INPUT_VEH_SELECT_NEXT_WEAPON,
	INPUT_VEH_SELECT_PREV_WEAPON,
	INPUT_VEH_ROOF,
	INPUT_VEH_JUMP,
	INPUT_VEH_GRAPPLING_HOOK,
	INPUT_VEH_SHUFFLE,
	INPUT_VEH_DROP_PROJECTILE,
	INPUT_VEH_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_FLY_ROLL_LR,
	INPUT_VEH_FLY_ROLL_LEFT_ONLY,
	INPUT_VEH_FLY_ROLL_RIGHT_ONLY,
	INPUT_VEH_FLY_PITCH_UD,
	INPUT_VEH_FLY_PITCH_UP_ONLY,
	INPUT_VEH_FLY_PITCH_DOWN_ONLY,
	INPUT_VEH_FLY_UNDERCARRIAGE,
	INPUT_VEH_FLY_ATTACK,
	INPUT_VEH_FLY_SELECT_NEXT_WEAPON,
	INPUT_VEH_FLY_SELECT_PREV_WEAPON,
	INPUT_VEH_FLY_SELECT_TARGET_LEFT,
	INPUT_VEH_FLY_SELECT_TARGET_RIGHT,
	INPUT_VEH_FLY_VERTICAL_FLIGHT_MODE,
	INPUT_VEH_FLY_DUCK,
	INPUT_VEH_FLY_ATTACK_CAMERA,
	INPUT_VEH_FLY_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_SUB_TURN_LR,
	INPUT_VEH_SUB_TURN_LEFT_ONLY,
	INPUT_VEH_SUB_TURN_RIGHT_ONLY,
	INPUT_VEH_SUB_PITCH_UD,
	INPUT_VEH_SUB_PITCH_UP_ONLY,
	INPUT_VEH_SUB_PITCH_DOWN_ONLY,
	INPUT_VEH_SUB_THROTTLE_UP,
	INPUT_VEH_SUB_THROTTLE_DOWN,
	INPUT_VEH_SUB_ASCEND,
	INPUT_VEH_SUB_DESCEND,
	INPUT_VEH_SUB_TURN_HARD_LEFT,
	INPUT_VEH_SUB_TURN_HARD_RIGHT,
	INPUT_VEH_SUB_MOUSE_CONTROL_OVERRIDE,
	INPUT_VEH_PUSHBIKE_PEDAL,
	INPUT_VEH_PUSHBIKE_SPRINT,
	INPUT_VEH_PUSHBIKE_FRONT_BRAKE,
	INPUT_VEH_PUSHBIKE_REAR_BRAKE,
	INPUT_MELEE_ATTACK_LIGHT,
	INPUT_MELEE_ATTACK_HEAVY,
	INPUT_MELEE_ATTACK_ALTERNATE,
	INPUT_MELEE_BLOCK,
	INPUT_PARACHUTE_DEPLOY,
	INPUT_PARACHUTE_DETACH,
	INPUT_PARACHUTE_TURN_LR,
	INPUT_PARACHUTE_TURN_LEFT_ONLY,
	INPUT_PARACHUTE_TURN_RIGHT_ONLY,
	INPUT_PARACHUTE_PITCH_UD,
	INPUT_PARACHUTE_PITCH_UP_ONLY,
	INPUT_PARACHUTE_PITCH_DOWN_ONLY,
	INPUT_PARACHUTE_BRAKE_LEFT,
	INPUT_PARACHUTE_BRAKE_RIGHT,
	INPUT_PARACHUTE_SMOKE,
	INPUT_PARACHUTE_PRECISION_LANDING,
	INPUT_MAP,
	INPUT_SELECT_WEAPON_UNARMED,
	INPUT_SELECT_WEAPON_MELEE,
	INPUT_SELECT_WEAPON_HANDGUN,
	INPUT_SELECT_WEAPON_SHOTGUN,
	INPUT_SELECT_WEAPON_SMG,
	INPUT_SELECT_WEAPON_AUTO_RIFLE,
	INPUT_SELECT_WEAPON_SNIPER,
	INPUT_SELECT_WEAPON_HEAVY,
	INPUT_SELECT_WEAPON_SPECIAL,
	INPUT_SELECT_CHARACTER_MICHAEL,
	INPUT_SELECT_CHARACTER_FRANKLIN,
	INPUT_SELECT_CHARACTER_TREVOR,
	INPUT_SELECT_CHARACTER_MULTIPLAYER,
	INPUT_SAVE_REPLAY_CLIP,
	INPUT_SPECIAL_ABILITY_PC,
	INPUT_CELLPHONE_UP,
	INPUT_CELLPHONE_DOWN,
	INPUT_CELLPHONE_LEFT,
	INPUT_CELLPHONE_RIGHT,
	INPUT_CELLPHONE_SELECT,
	INPUT_CELLPHONE_CANCEL,
	INPUT_CELLPHONE_OPTION,
	INPUT_CELLPHONE_EXTRA_OPTION,
	INPUT_CELLPHONE_SCROLL_FORWARD,
	INPUT_CELLPHONE_SCROLL_BACKWARD,
	INPUT_CELLPHONE_CAMERA_FOCUS_LOCK,
	INPUT_CELLPHONE_CAMERA_GRID,
	INPUT_CELLPHONE_CAMERA_SELFIE,
	INPUT_CELLPHONE_CAMERA_DOF,
	INPUT_CELLPHONE_CAMERA_EXPRESSION,
	INPUT_FRONTEND_DOWN,
	INPUT_FRONTEND_UP,
	INPUT_FRONTEND_LEFT,
	INPUT_FRONTEND_RIGHT,
	INPUT_FRONTEND_RDOWN,
	INPUT_FRONTEND_RUP,
	INPUT_FRONTEND_RLEFT,
	INPUT_FRONTEND_RRIGHT,
	INPUT_FRONTEND_AXIS_X,
	INPUT_FRONTEND_AXIS_Y,
	INPUT_FRONTEND_RIGHT_AXIS_X,
	INPUT_FRONTEND_RIGHT_AXIS_Y,
	INPUT_FRONTEND_PAUSE,
	INPUT_FRONTEND_PAUSE_ALTERNATE,
	INPUT_FRONTEND_ACCEPT,
	INPUT_FRONTEND_CANCEL,
	INPUT_FRONTEND_X,
	INPUT_FRONTEND_Y,
	INPUT_FRONTEND_LB,
	INPUT_FRONTEND_RB,
	INPUT_FRONTEND_LT,
	INPUT_FRONTEND_RT,
	INPUT_FRONTEND_LS,
	INPUT_FRONTEND_RS,
	INPUT_FRONTEND_LEADERBOARD,
	INPUT_FRONTEND_SOCIAL_CLUB,
	INPUT_FRONTEND_SOCIAL_CLUB_SECONDARY,
	INPUT_FRONTEND_DELETE,
	INPUT_FRONTEND_ENDSCREEN_ACCEPT,
	INPUT_FRONTEND_ENDSCREEN_EXPAND,
	INPUT_FRONTEND_SELECT,
	INPUT_SCRIPT_LEFT_AXIS_X,
	INPUT_SCRIPT_LEFT_AXIS_Y,
	INPUT_SCRIPT_RIGHT_AXIS_X,
	INPUT_SCRIPT_RIGHT_AXIS_Y,
	INPUT_SCRIPT_RUP,
	INPUT_SCRIPT_RDOWN,
	INPUT_SCRIPT_RLEFT,
	INPUT_SCRIPT_RRIGHT,
	INPUT_SCRIPT_LB,
	INPUT_SCRIPT_RB,
	INPUT_SCRIPT_LT,
	INPUT_SCRIPT_RT,
	INPUT_SCRIPT_LS,
	INPUT_SCRIPT_RS,
	INPUT_SCRIPT_PAD_UP,
	INPUT_SCRIPT_PAD_DOWN,
	INPUT_SCRIPT_PAD_LEFT,
	INPUT_SCRIPT_PAD_RIGHT,
	INPUT_SCRIPT_SELECT,
	INPUT_CURSOR_ACCEPT,
	INPUT_CURSOR_CANCEL,
	INPUT_CURSOR_X,
	INPUT_CURSOR_Y,
	INPUT_CURSOR_SCROLL_UP,
	INPUT_CURSOR_SCROLL_DOWN,
	INPUT_ENTER_CHEAT_CODE,
	INPUT_INTERACTION_MENU,
	INPUT_MP_TEXT_CHAT_ALL,
	INPUT_MP_TEXT_CHAT_TEAM,
	INPUT_MP_TEXT_CHAT_FRIENDS,
	INPUT_MP_TEXT_CHAT_CREW,
	INPUT_PC_PUSH_TO_TALK,
	INPUT_CREATOR_LS,
	INPUT_CREATOR_RS,
	INPUT_CREATOR_LT,
	INPUT_CREATOR_RT,
	INPUT_CREATOR_MENU_TOGGLE,
	INPUT_CREATOR_ACCEPT,
	INPUT_CREATOR_DELETE,
	INPUT_ATTACK2,
	INPUT_RAPPEL_JUMP,
	INPUT_RAPPEL_LONG_JUMP,
	INPUT_RAPPEL_SMASH_WINDOW,
	INPUT_PREV_WEAPON,
	INPUT_NEXT_WEAPON,
	INPUT_MELEE_ATTACK1,
	INPUT_MELEE_ATTACK2,
	INPUT_WHISTLE,
	INPUT_MOVE_LEFT,
	INPUT_MOVE_RIGHT,
	INPUT_MOVE_UP,
	INPUT_MOVE_DOWN,
	INPUT_LOOK_LEFT,
	INPUT_LOOK_RIGHT,
	INPUT_LOOK_UP,
	INPUT_LOOK_DOWN,
	INPUT_SNIPER_ZOOM_IN,
	INPUT_SNIPER_ZOOM_OUT,
	INPUT_SNIPER_ZOOM_IN_ALTERNATE,
	INPUT_SNIPER_ZOOM_OUT_ALTERNATE,
	INPUT_VEH_MOVE_LEFT,
	INPUT_VEH_MOVE_RIGHT,
	INPUT_VEH_MOVE_UP,
	INPUT_VEH_MOVE_DOWN,
	INPUT_VEH_GUN_LEFT,
	INPUT_VEH_GUN_RIGHT,
	INPUT_VEH_GUN_UP,
	INPUT_VEH_GUN_DOWN,
	INPUT_VEH_LOOK_LEFT,
	INPUT_VEH_LOOK_RIGHT,
	INPUT_REPLAY_START_STOP_RECORDING,
	INPUT_REPLAY_START_STOP_RECORDING_SECONDARY,
	INPUT_SCALED_LOOK_LR,
	INPUT_SCALED_LOOK_UD,
	INPUT_SCALED_LOOK_UP_ONLY,
	INPUT_SCALED_LOOK_DOWN_ONLY,
	INPUT_SCALED_LOOK_LEFT_ONLY,
	INPUT_SCALED_LOOK_RIGHT_ONLY,
	INPUT_REPLAY_MARKER_DELETE,
	INPUT_REPLAY_CLIP_DELETE,
	INPUT_REPLAY_PAUSE,
	INPUT_REPLAY_REWIND,
	INPUT_REPLAY_FFWD,
	INPUT_REPLAY_NEWMARKER,
	INPUT_REPLAY_RECORD,
	INPUT_REPLAY_SCREENSHOT,
	INPUT_REPLAY_HIDEHUD,
	INPUT_REPLAY_STARTPOINT,
	INPUT_REPLAY_ENDPOINT,
	INPUT_REPLAY_ADVANCE,
	INPUT_REPLAY_BACK,
	INPUT_REPLAY_TOOLS,
	INPUT_REPLAY_RESTART,
	INPUT_REPLAY_SHOWHOTKEY,
	INPUT_REPLAY_CYCLEMARKERLEFT,
	INPUT_REPLAY_CYCLEMARKERRIGHT,
	INPUT_REPLAY_FOVINCREASE,
	INPUT_REPLAY_FOVDECREASE,
	INPUT_REPLAY_CAMERAUP,
	INPUT_REPLAY_CAMERADOWN,
	INPUT_REPLAY_SAVE,
	INPUT_REPLAY_TOGGLETIME,
	INPUT_REPLAY_TOGGLETIPS,
	INPUT_REPLAY_PREVIEW,
	INPUT_REPLAY_TOGGLE_TIMELINE,
	INPUT_REPLAY_TIMELINE_PICKUP_CLIP,
	INPUT_REPLAY_TIMELINE_DUPLICATE_CLIP,
	INPUT_REPLAY_TIMELINE_PLACE_CLIP,
	INPUT_REPLAY_CTRL,
	INPUT_REPLAY_TIMELINE_SAVE,
	INPUT_REPLAY_PREVIEW_AUDIO,
	INPUT_VEH_DRIVE_LOOK,
	INPUT_VEH_DRIVE_LOOK2,
	INPUT_VEH_FLY_ATTACK2,
	INPUT_RADIO_WHEEL_UD,
	INPUT_RADIO_WHEEL_LR,
	INPUT_VEH_SLOWMO_UP,
	INPUT_VEH_SLOWMO_UP_ONLY,
	INPUT_VEH_SLOWMO_DOWN_ONLY,
	INPUT_VEH_HYDRAULICS_CONTROL_TOGGLE,
	INPUT_VEH_HYDRAULICS_CONTROL_LEFT,
	INPUT_VEH_HYDRAULICS_CONTROL_RIGHT,
	INPUT_VEH_HYDRAULICS_CONTROL_UP,
	INPUT_VEH_HYDRAULICS_CONTROL_DOWN,
	INPUT_VEH_HYDRAULICS_CONTROL_LR,
	INPUT_VEH_HYDRAULICS_CONTROL_UD,
	INPUT_SWITCH_VISOR,
	INPUT_VEH_MELEE_HOLD,
	INPUT_VEH_MELEE_LEFT,
	INPUT_VEH_MELEE_RIGHT,
	INPUT_MAP_POI,
	INPUT_REPLAY_SNAPMATIC_PHOTO,
	INPUT_VEH_CAR_JUMP,
	INPUT_VEH_ROCKET_BOOST,
	INPUT_VEH_FLY_BOOST,
	INPUT_VEH_PARACHUTE,
	INPUT_VEH_BIKE_WINGS,
	INPUT_VEH_FLY_BOMB_BAY,
	INPUT_VEH_FLY_COUNTER,
	INPUT_VEH_TRANSFORM,
	INPUT_QUAD_LOCO_REVERSE,
	INPUT_RESPAWN_FASTER,
	INPUT_HUDMARKER_SELECT,
	INPUT_EAT_SNACK,
	INPUT_USE_ARMOR,
	MAX_INPUTS
};