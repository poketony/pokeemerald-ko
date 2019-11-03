LittlerootTown_MapScripts:: @ 81E7DCB
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScript1_1E7DDB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScript2_1E7EC1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScript2_1E7FE2
	.byte 0

LittlerootTown_MapScript1_1E7DDB: @ 81E7DDB
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	call_if_eq LittlerootTown_EventScript_1E7E67
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_1E7E6F
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	call_if_eq LittlerootTown_EventScript_1E7E92
	compare VAR_LITTLEROOT_HOUSES_STATE, 4
	call_if_eq LittlerootTown_EventScript_1E7E5C
	compare VAR_LITTLEROOT_HOUSES_STATE_2, 4
	call_if_eq LittlerootTown_EventScript_1E7E5C
	compare VAR_OLDALE_RIVAL_STATE, 1
	call_if_eq LittlerootTown_EventScript_1E7E53
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_eq LittlerootTown_EventScript_1E7E4F
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	call_if_eq LittlerootTown_EventScript_1E7E4B
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	call_if_eq LittlerootTown_EventScript_1E7E45
	end

LittlerootTown_EventScript_1E7E45:: @ 81E7E45
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_1E7E4B:: @ 81E7E4B
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_1E7E4F:: @ 81E7E4F
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_1E7E53:: @ 81E7E53
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_1E7E5C:: @ 81E7E5C
	setvar VAR_LITTLEROOT_HOUSES_STATE, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 5
	return

LittlerootTown_EventScript_1E7E67:: @ 81E7E67
	setobjectxyperm 4, 14, 8
	return

LittlerootTown_EventScript_1E7E6F:: @ 81E7E6F
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_1E7E86
	setobjectxyperm 1, 10, 1
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_1E7E86:: @ 81E7E86
	setobjectxyperm 1, 7, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_1E7E92:: @ 81E7E92
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E7EB1
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E7EB9
	return

LittlerootTown_EventScript_1E7EB1:: @ 81E7EB1
	setobjectxyperm 4, 5, 9
	return

LittlerootTown_EventScript_1E7EB9:: @ 81E7EB9
	setobjectxyperm 4, 14, 9
	return

LittlerootTown_MapScript2_1E7EC1: @ 81E7EC1
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_1E7EDB
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_1E7EF9
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_1E7FB1
	.2byte 0

LittlerootTown_EventScript_1E7EDB:: @ 81E7EDB
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_1E7F17
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_1E7EF9:: @ 81E7EF9
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_1E7F17
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 2, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_1E7F17:: @ 81E7F17
	delay 15
	playse SE_DANSA
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_1E7FAC
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject 4
	applymovement 4, LittlerootTown_Movement_1E7F98
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement 4, LittlerootTown_Movement_1E7F9A
	waitmovement 0
	msgbox LittlerootTown_Text_1E86BC, MSGBOX_DEFAULT
	closemessage
	applymovement 4, LittlerootTown_Movement_1E7F9D
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_1E7FA4
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E7FA1
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_1E7FA9
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_Movement_1E7F98: @ 81E7F98
	walk_down
	step_end

LittlerootTown_Movement_1E7F9A: @ 81E7F9A
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_Movement_1E7F9D: @ 81E7F9D
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_1E7FA1: @ 81E7FA1
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_1E7FA4: @ 81E7FA4
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E7FA9: @ 81E7FA9
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_1E7FAC: @ 81E7FAC
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_1E7FB1:: @ 81E7FB1
	lockall
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox LittlerootTown_Text_1E8DA2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_MapScript2_1E7FE2: @ 81E7FE2
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_1E7FEC
	.2byte 0

LittlerootTown_EventScript_1E7FEC:: @ 81E7FEC
	addobject 8
	addobject 7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_1E8004
	goto LittlerootTown_EventScript_1E8013
	end

LittlerootTown_EventScript_1E8004:: @ 81E8004
	setobjectxy 7, 6, 10
	setobjectxy 8, 5, 10
	end

LittlerootTown_EventScript_1E8013:: @ 81E8013
	setobjectxy 7, 13, 10
	setobjectxy 8, 14, 10
	end

LittlerootTown_EventScript_1E8022:: @ 81E8022
	msgbox LittlerootTown_Text_1E8ACF, MSGBOX_NPC
	end

LittlerootTown_EventScript_1E802B:: @ 81E802B
	msgbox LittlerootTown_Text_1E8B25, MSGBOX_NPC
	end

LittlerootTown_EventScript_1E8034:: @ 81E8034
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_1E8087
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_1E807A
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_ne LittlerootTown_EventScript_1E805D
	msgbox LittlerootTown_Text_1E8BB8, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_1E805D:: @ 81E805D
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_1E8C3A, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	release
	end

LittlerootTown_EventScript_1E807A:: @ 81E807A
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_1E8CE3, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_1E8087:: @ 81E8087
	msgbox LittlerootTown_Text_1E8D07, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_1E8091:: @ 81E8091
	lockall
	applymovement 1, LittlerootTown_Movement_1E80D1
	waitmovement 0
	call LittlerootTown_EventScript_1E80AD
	applymovement 1, LittlerootTown_Movement_1E80E1
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_1E80AD:: @ 81E80AD
	msgbox LittlerootTown_Text_1E8BB8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, LittlerootTown_Movement_1E80DF
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_1E80EB
	waitmovement 0
	msgbox LittlerootTown_Text_1E8C07, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_1E80D1: @ 81E80D1
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_1E80DF: @ 81E80DF
	walk_down
	step_end

LittlerootTown_Movement_1E80E1: @ 81E80E1
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_down
	step_end

LittlerootTown_Movement_1E80EB: @ 81E80EB
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_1E80EF:: @ 81E80EF
	lockall
	applymovement 1, LittlerootTown_Movement_1E810B
	waitmovement 0
	call LittlerootTown_EventScript_1E80AD
	applymovement 1, LittlerootTown_Movement_1E8118
	waitmovement 0
	releaseall
	end

LittlerootTown_Movement_1E810B: @ 81E810B
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

LittlerootTown_Movement_1E8118: @ 81E8118
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_EventScript_1E811F:: @ 81E811F
	lockall
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_1E8C3A, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	releaseall
	end

LittlerootTown_EventScript_1E8151:: @ 81E8151
	msgbox LittlerootTown_Text_1E8D32, MSGBOX_SIGN
	end

LittlerootTown_EventScript_1E815A:: @ 81E815A
	msgbox LittlerootTown_Text_1E8D69, MSGBOX_SIGN
	end

LittlerootTown_EventScript_1E8163:: @ 81E8163
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E817D
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E8186
	releaseall
	end

LittlerootTown_EventScript_1E817D:: @ 81E817D
	msgbox LittlerootTown_Text_1E8D83, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_1E8186:: @ 81E8186
	msgbox LittlerootTown_Text_1E8D8E, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_1E818F:: @ 81E818F
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E81A9
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E81B2
	releaseall
	end

LittlerootTown_EventScript_1E81A9:: @ 81E81A9
	msgbox LittlerootTown_Text_1E8D8E, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_1E81B2:: @ 81E81B2
	msgbox LittlerootTown_Text_1E8D83, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_1E81BB:: @ 81E81BB
	lockall
	setvar VAR_0x8008, 0
	setobjectxy 4, 10, 9
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81CE:: @ 81E81CE
	lockall
	setvar VAR_0x8008, 1
	setobjectxy 4, 11, 9
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81E1:: @ 81E81E1
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81ED:: @ 81E81ED
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81F9:: @ 81E81F9
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E8205:: @ 81E8205
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E8211:: @ 81E8211
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E8297
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E82A2
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E8281
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E828C
	msgbox LittlerootTown_Text_1E87E1, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E82AD
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E82F0
	call LittlerootTown_EventScript_1E8693
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E8405
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E8448
	goto LittlerootTown_EventScript_1E8686
	end

LittlerootTown_EventScript_1E8281:: @ 81E8281
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_1E828C:: @ 81E828C
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_1E8297:: @ 81E8297
	applymovement 4, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LittlerootTown_EventScript_1E82A2:: @ 81E82A2
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

LittlerootTown_EventScript_1E82AD:: @ 81E82AD
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E8333
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8348
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E835D
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E8372
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E8387
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E839C
	return

LittlerootTown_EventScript_1E82F0:: @ 81E82F0
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E8333
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8348
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E83B1
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E83C6
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E83DB
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E83F0
	return

LittlerootTown_EventScript_1E8333:: @ 81E8333
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85D1
	waitmovement 0
	return

LittlerootTown_EventScript_1E8348:: @ 81E8348
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85D8
	waitmovement 0
	return

LittlerootTown_EventScript_1E835D:: @ 81E835D
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85DF
	waitmovement 0
	return

LittlerootTown_EventScript_1E8372:: @ 81E8372
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85E4
	waitmovement 0
	return

LittlerootTown_EventScript_1E8387:: @ 81E8387
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85EA
	waitmovement 0
	return

LittlerootTown_EventScript_1E839C:: @ 81E839C
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85ED
	waitmovement 0
	return

LittlerootTown_EventScript_1E83B1:: @ 81E83B1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85F1
	waitmovement 0
	return

LittlerootTown_EventScript_1E83C6:: @ 81E83C6
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85F5
	waitmovement 0
	return

LittlerootTown_EventScript_1E83DB:: @ 81E83DB
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85F8
	waitmovement 0
	return

LittlerootTown_EventScript_1E83F0:: @ 81E83F0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement 4, LittlerootTown_Movement_1E85FE
	waitmovement 0
	return

LittlerootTown_EventScript_1E8405:: @ 81E8405
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E848B
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8496
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E84A1
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E84C7
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E84ED
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E8513
	return

LittlerootTown_EventScript_1E8448:: @ 81E8448
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E848B
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8496
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E8539
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E855F
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E8585
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E85AB
	return

LittlerootTown_EventScript_1E848B:: @ 81E848B
	applymovement 4, LittlerootTown_Movement_1E8603
	waitmovement 0
	return

LittlerootTown_EventScript_1E8496:: @ 81E8496
	applymovement 4, LittlerootTown_Movement_1E8609
	waitmovement 0
	return

LittlerootTown_EventScript_1E84A1:: @ 81E84A1
	applymovement 4, LittlerootTown_Movement_1E860F
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E84C7:: @ 81E84C7
	applymovement 4, LittlerootTown_Movement_1E8615
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E84ED:: @ 81E84ED
	applymovement 4, LittlerootTown_Movement_1E861C
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8513:: @ 81E8513
	applymovement 4, LittlerootTown_Movement_1E8620
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8539:: @ 81E8539
	applymovement 4, LittlerootTown_Movement_1E8625
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E855F:: @ 81E855F
	applymovement 4, LittlerootTown_Movement_1E862A
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8585:: @ 81E8585
	applymovement 4, LittlerootTown_Movement_1E862E
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E85AB:: @ 81E85AB
	applymovement 4, LittlerootTown_Movement_1E8635
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_1E85D1: @ 81E85D1
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_1E85D8: @ 81E85D8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_1E85DF: @ 81E85DF
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85E4: @ 81E85E4
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85EA: @ 81E85EA
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85ED: @ 81E85ED
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85F1: @ 81E85F1
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85F5: @ 81E85F5
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85F8: @ 81E85F8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85FE: @ 81E85FE
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E8603: @ 81E8603
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_1E8609: @ 81E8609
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_1E860F: @ 81E860F
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8615: @ 81E8615
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E861C: @ 81E861C
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8620: @ 81E8620
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8625: @ 81E8625
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E862A: @ 81E862A
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E862E: @ 81E862E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8635: @ 81E8635
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E863B: @ 81E863B
	walk_up
	step_end

LittlerootTown_EventScript_1E863D:: @ 81E863D
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E8281
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E828C
	call LittlerootTown_EventScript_1E8693
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement 4, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat 4, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_1E8686
	end

LittlerootTown_EventScript_1E8686:: @ 81E8686
	removeobject 4
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_1E8693:: @ 81E8693
	msgbox LittlerootTown_Text_1E87F0, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message LittlerootTown_Text_1E8925
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_1E894F, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_1E8A03, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_Text_1E86BC: @ 81E86BC
	.string "엄마: {PLAYER} 고생했어!\p"
	.string "계속 트럭이 흔들려서\n"
	.string "정신없었지?\p"
	.string "여기가 미로마을이란다!\p"
	.string "어떠니? 이게 우리 가족의\n"
	.string "새로운 집이야!\p"
	.string "살짝 고풍스러우면서도\n"
	.string "살기 좋은 곳일 거 같지 않니?\p"
	.string "이번에는 {PLAYER}\n" 
	.string "네 방도 있단다!\p"
	.string "자 그럼 안으로 들어가자!$"
	//ママ『{PLAYER} おつかれさま!ｐ
	//ながいあいだ トラックに ゆられてｎ
	//たいへん だったでしょ?ｐ
	//ここが ミシロタウンよ!ｐ
	//どう? これが わたしたちのｎ
	//あたらしい おうち!ｐ
	//ちょっと こふうな かんじでｎ
	//すみやすそうな ところ でしょ?ｐ
	//こんどは {PLAYER}の おへやも あるのよ!ｎ
	//さあ なかに はいりましょ!
LittlerootTown_Text_1E87E1: @ 81E87E1
	.string "엄마: 잠깐 기다리렴 {PLAYER}!$"

LittlerootTown_Text_1E87F0: @ 81E87F0
	.string "엄마: {PLAYER}! {PLAYER}!\n"
	.string "털보박사님께는 인사했니?\p"
	.string "어머! 귀여운 포켓몬!\n"
	.string "털보박사님께 받았구나\p"
	.string "역시 피는 못 속여...\n"
	.string "포켓몬이랑 함께 있는 모습이\l"
	.string "정말 그럴듯하구나!\p"
	.string "자! 모험을 떠나려면\n"
	.string "러닝슈즈를 신어야지!\p"
	.string "여러 장소를\n"
	.string "달릴 수 있게 될 거야!$"

LittlerootTown_Text_1E8925: @ 81E8925
	.string "{PLAYER}{K_EUNNEUN}\n"
	.string "러닝슈즈로 갈아 신었다!$"

LittlerootTown_Text_1E894F: @ 81E894F
	.string "엄마: 음- 그리고\n"
	.string "설명서를 읽어보자꾸나\p"
	.string "“러닝슈즈는\n"
	.string " B 버튼을 누르면 지금보다\l"
	.string " 빨리 달릴 수 있게 해 줍니다!\p"
	.string " 러닝슈즈를 신고\n"
	.string " 마음껏 달립시다!”$"

LittlerootTown_Text_1E8A03: @ 81E8A03
	.string "…… …… ……\n"
	.string "…… …… ……\p"
	.string "네가 자신의 포켓몬을\n"
	.string "가지게 될 줄이야...\l"
	.string "아빠가 알면 정말 기뻐하시겠다!\p"
	.string "……그치만 무리는 하지 마렴\n"
	.string "무슨 일이 생기면\l"
	.string "집으로 와도 되니까\p"
	.string "그럼 힘내!$"

LittlerootTown_Text_1E8ACF: @ 81E8ACF
	.string "PC를 쓰면\n"
	.string "아이템이나 포켓몬을\l"
	.string "보관할 수 있다고 하더라고!\p"
	.string "과학의 힘은 정말 대단해!$"

LittlerootTown_Text_1E8B25: @ 81E8B25
	.string "계속 연구소에만 틀어박혀서\n"
	.string "연구만 하고 있다고 생각했는데\p"
	.string "또 갑자기\n"
	.string "산이나 들로 뛰쳐나가니...\p"
	.string "털보박사님은 도대체\n"
	.string "언제 집에 가시는 걸까?$"

LittlerootTown_Text_1E8BB8: @ 81E8BB8
	.string "있지-있지-있지-!\p"
	.string "여기 앞에 있는 도로\n"
	.string "풀숲으로 들어가면\l"
	.string "야생 포켓몬이 나와버려!$"

LittlerootTown_Text_1E8C07: @ 81E8C07
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_1E8C3A: @ 81E8C3A
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_1E8CE3: @ 81E8CE3
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_1E8D07: @ 81E8D07
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_1E8D32: @ 81E8D32
	.string "여기는 미로마을\n"
	.string "어떤 색에도 물들지 않는 마을$"

LittlerootTown_Text_1E8D69: @ 81E8D69
	.string "“털보박사 포켓몬 연구소”$"

LittlerootTown_Text_1E8D83: @ 81E8D83
	.string "“{PLAYER}의 집”$"

LittlerootTown_Text_1E8D8E: @ 81E8D8E
	.string "“털보박사의 집”$"

LittlerootTown_Text_1E8DA2: @ 81E8DA2
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

