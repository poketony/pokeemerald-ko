BattleFrontier_BattleArenaBattleRoom_MapScripts:: @ 8257487
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_MapScript1_2574A0
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScript2_2574D2
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_MapScript2_257C0C
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_MapScript1_25749C
	.byte 0

BattleFrontier_BattleArenaBattleRoom_MapScript1_25749C: @ 825749C
	special OffsetCameraForBattle
	end

BattleFrontier_BattleArenaBattleRoom_MapScript1_2574A0: @ 82574A0
	setvar VAR_0x8004, 5
	special CallFrontierUtilFunc
	call BattleFrontier_BattleArenaBattleRoom_EventScript_2574AE
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_2574AE:: @ 82574AE
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2574C6
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2574CC
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_2574C6:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_2574CC:: @ 82574CC
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleArenaBattleRoom_MapScript2_2574D2: @ 82574D2
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_2574DC
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_2574DC:: @ 82574DC
	lockall
	showobjectat 8, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE2
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25752E
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257C08
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BEB
	setvar VAR_TEMP_2, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25752E:: @ 825752E
	setvar VAR_0x8004, 3
	special sub_8161F74
	addobject 7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BEF
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C3D, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE5
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	setvar VAR_0x8004, 6
	special CallBattleArenaFunction
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C68, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C93, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE5
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	setvar VAR_0x8004, 5
	special CallBattlePalaceFunction
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_257630

BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB:: @ 82575DB
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 1, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 2, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 3, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	applymovement 4, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	playse SE_W173
	waitse
	waitmovement 0
	setvar VAR_0x8004, 6
	special CallBattleArenaFunction
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CCE, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257615:: @ 8257615
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special CallFrontierUtilFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257630:: @ 8257630
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special CallFrontierUtilFunc
	switch VAR_RESULT
	case 7, BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BFA
	waitmovement 0
	removeobject 7
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257C08
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BEB
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CE9, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special CallFrontierUtilFunc
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0:: @ 82576B0
	setvar VAR_0x8004, 9
	special CallFrontierUtilFunc
	copyvar VAR_TEMP_F, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_2578BC
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special CallFrontierUtilFunc
	compare VAR_RESULT, 1
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257870
	compare VAR_RESULT, 2
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257877
	compare VAR_RESULT, 3
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25787E
	compare VAR_RESULT, 4
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257885
	compare VAR_RESULT, 5
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25788C
	compare VAR_RESULT, 6
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257893
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257768
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_25783A
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_25779E
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_257768:: @ 8257768
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_25783A
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25779E:: @ 825779E
	message BattleFrontier_BattleArenaBattleRoom_Text_257F04
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_2577D0
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_2577D0:: @ 82577D0
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8B4
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA:: @ 82577DA
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257E6B, MSGBOX_YESNO
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_25789A
	case 127, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_257808:: @ 8257808
	message BattleFrontier_BattleArenaBattleRoom_Text_257E9E
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, 0
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257615
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2576B0

BattleFrontier_BattleArenaBattleRoom_EventScript_25783A:: @ 825783A
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	waitmovement 0
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_25752E
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257852:: @ 8257852
	delay 60
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 3
	special CallFrontierUtilFunc
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
	waitstate

BattleFrontier_BattleArenaBattleRoom_EventScript_257870:: @ 8257870
	message BattleFrontier_BattleArenaBattleRoom_Text_257D17
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257877:: @ 8257877
	message BattleFrontier_BattleArenaBattleRoom_Text_257D50
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25787E:: @ 825787E
	message BattleFrontier_BattleArenaBattleRoom_Text_257D88
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257885:: @ 8257885
	message BattleFrontier_BattleArenaBattleRoom_Text_257DC1
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25788C:: @ 825788C
	message BattleFrontier_BattleArenaBattleRoom_Text_257DF9
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257893:: @ 8257893
	message BattleFrontier_BattleArenaBattleRoom_Text_257E31
	waitmessage
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_25789A:: @ 825789A
	message BattleFrontier_BattleArenaBattleRoom_Text_257EDB
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 2
	special CallBattleArenaFunction
	playse SE_SAVE
	waitse
	fadescreen 1
	setvar VAR_0x8004, 4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleArenaBattleRoom_EventScript_2578BC:: @ 82578BC
	compare VAR_TEMP_2, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257F45, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1

BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4:: @ 82578D4
	message BattleFrontier_BattleArenaBattleRoom_Text_257FBB
	waitmessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_23E8E0
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_25792B
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257961
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_25779E
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4

BattleFrontier_BattleArenaBattleRoom_EventScript_25792B:: @ 825792B
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, 1
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257961
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_2577DA
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257808
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_2578D4

BattleFrontier_BattleArenaBattleRoom_EventScript_257961:: @ 8257961
	call BattleFrontier_BattleArenaBattleRoom_EventScript_242170
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	applymovement 5, BattleFrontier_BattleArenaBattleRoom_Movement_257BED
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C3D, MSGBOX_DEFAULT
	closemessage
	applymovement 8, BattleFrontier_BattleArenaBattleRoom_Movement_257BE4
	waitmovement 0
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	playse SE_W187
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257FED, MSGBOX_DEFAULT
	closemessage
	addobject 7
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF4
	waitmovement 0
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF2
	waitmovement 0
	switch VAR_TEMP_F
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_257AA5
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F
	case 4, BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25801C, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C30
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25804E, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C3A
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258068, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257A3F:: @ 8257A3F
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25810D, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257A5C
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB

BattleFrontier_BattleArenaBattleRoom_EventScript_257A5C:: @ 8257A5C
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF1
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_25813F, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleArenaBattleRoom_Text_25819C
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2581CF, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_257852

BattleFrontier_BattleArenaBattleRoom_EventScript_257AA5:: @ 8257AA5
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258213, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 7
	special CallFrontierUtilFunc
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C30
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582A2, MSGBOX_DEFAULT
	closemessage
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257C3A
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582BB, MSGBOX_DEFAULT

BattleFrontier_BattleArenaBattleRoom_EventScript_257AF8:: @ 8257AF8
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_2582F9, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257B15
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_2575DB

BattleFrontier_BattleArenaBattleRoom_EventScript_257B15:: @ 8257B15
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9
	setvar VAR_0x8004, 12
	special CallFrontierUtilFunc
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_257852
	applymovement 7, BattleFrontier_BattleArenaBattleRoom_Movement_257BF1
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258323, MSGBOX_DEFAULT
	playfanfare MUS_ME_SYMBOLGET
	message BattleFrontier_BattleArenaBattleRoom_Text_25835B
	waitmessage
	waitfanfare
	setvar VAR_0x8004, 13
	special CallFrontierUtilFunc
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_258383, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_257852

BattleFrontier_BattleArenaBattleRoom_EventScript_257B5E:: @ 8257B5E
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257C93, MSGBOX_DEFAULT
	call BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257B6C:: @ 8257B6C
FallarborTown_BattleTentBattleRoom_EventScript_257B6C:: @ 8257B6C
	closemessage
	setvar VAR_TEMP_2, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 0
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_ARENA
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_0x8004, 18
	special CallFrontierUtilFunc
	special HealPlayerParty
	setvar VAR_0x8004, 21
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleArenaBattleRoom_EventScript_257BA9:: @ 8257BA9
	applymovement 9, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 1, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 2, BattleFrontier_BattleArenaBattleRoom_Movement_257C02
	applymovement 3, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	applymovement 4, BattleFrontier_BattleArenaBattleRoom_Movement_257C05
	playse SE_BAN
	waitse
	waitmovement 0
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_257CB3, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleArenaBattleRoom_EventScript_241EBA
	return

BattleFrontier_BattleArenaBattleRoom_Movement_257BE2: @ 8257BE2
	walk_right
	walk_right

BattleFrontier_BattleArenaBattleRoom_Movement_257BE4: @ 8257BE4
	walk_right

BattleFrontier_BattleArenaBattleRoom_Movement_257BE5: @ 8257BE5
	walk_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BE7: @ 8257BE7
	walk_left
	walk_left
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BEB: @ 8257BEB
	walk_in_place_fastest_up
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BED: @ 8257BED
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BEF: @ 8257BEF
	walk_left
	walk_left

BattleFrontier_BattleArenaBattleRoom_Movement_257BF1: @ 8257BF1
	walk_left

BattleFrontier_BattleArenaBattleRoom_Movement_257BF2: @ 8257BF2
	walk_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BF4: @ 8257BF4
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257BFA: @ 8257BFA
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C02: @ 8257C02
	disable_jump_landing_ground_effect
	jump_in_place_down
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C05: @ 8257C05
	disable_jump_landing_ground_effect
	jump_in_place_up
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C08: @ 8257C08
	walk_in_place_fastest_down
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C0A: @ 8257C0A
	walk_in_place_fastest_right
	step_end

BattleFrontier_BattleArenaBattleRoom_MapScript2_257C0C: @ 8257C0C
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_257C16
	.2byte 0

BattleFrontier_BattleArenaBattleRoom_EventScript_257C16:: @ 8257C16
	hideobjectat 8, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
	removeobject 7
	call BattleFrontier_BattleArenaBattleRoom_EventScript_24BCDC
	applymovement EVENT_OBJ_ID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_24C773
	setvar VAR_TEMP_1, 1
	end

BattleFrontier_BattleArenaBattleRoom_Movement_257C30: @ 8257C30
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Movement_257C3A: @ 8257C3A
	walk_down
	walk_in_place_fastest_left
	step_end

BattleFrontier_BattleArenaBattleRoom_Text_257C3D: @ 8257C3D
	.string "심판: 트레이너 {PLAYER}!\n"
	.string "앞으로---!$"
	//しんぱん『トレ-ナ- {PLAYER}!\n
	//まえへ---!

BattleFrontier_BattleArenaBattleRoom_Text_257C68: @ 8257C68
	.string "심판: 트레이너 {STR_VAR_1}!\n"
	.string "앞으로---!$"
	//しんぱん『トレ-ナ- {STR_VAR_1}!\n
	//まえへ---!

BattleFrontier_BattleArenaBattleRoom_Text_257C93: @ 8257C93
FallarborTown_BattleTentBattleRoom_Text_257C93: @ 8257C93
	.string "심판: 연승 팀 배틀!\n"
	.string "시작---!!$"
	//しんぱん『かちぬきチ-ムバトル!ｎ
	//はじめ---!!

BattleFrontier_BattleArenaBattleRoom_Text_257CB3: @ 8257CB3
FallarborTown_BattleTentBattleRoom_Text_257CB3: @ 8257CB3
	.string "심판: 승자는---!\n"
	.string "{PLAYER}!!$"
	//しんぱん『しょうしゃ---!ｎ
	//{PLAYER}!!

BattleFrontier_BattleArenaBattleRoom_Text_257CCE: @ 8257CCE
FallarborTown_BattleTentBattleRoom_Text_257CCE: @ 8257CCE
	.string "심판: 승자는---!\n"
	.string "{STR_VAR_1}!!$"
	//しんぱん『しょうしゃ---!ｎ
	//{STR_VAR_1}!!

BattleFrontier_BattleArenaBattleRoom_Text_257CE9: @ 8257CE9
FallarborTown_BattleTentBattleRoom_Text_257CE9: @ 8257CE9
	.string "포켓몬의 체력을\n"
	.string "회복시켜 드리겠습니다!$"
	//ポケモンの たいりょくをｎ
	//かいふく いたしますぞ!

BattleFrontier_BattleArenaBattleRoom_Text_257D17: @ 8257D17
FallarborTown_BattleTentBattleRoom_Text_257D17: @ 8257D17
	.string "다음은 2명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 2にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257D50: @ 8257D50
FallarborTown_BattleTentBattleRoom_Text_257D50: @ 8257D50
	.string "다음은 3명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 3にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257D88: @ 8257D88
	.string "다음은 4명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 4にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257DC1: @ 8257DC1
	.string "다음은 5명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 5にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257DF9: @ 8257DF9
	.string "다음은 6명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 6にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257E31: @ 8257E31
	.string "다음은 7명째 상대입니다!\n"
	.string "준비되셨습니까?$"
	//つぎは 7にんめの あいてですぞ!ｎ
	//じゅんびは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257E6B: @ 8257E6B
FallarborTown_BattleTentBattleRoom_Text_257E6B: @ 8257E6B
	.string "리포트를 작성하고\n"
	.string "중단할까요?$"
	//レポ-トを かいてｎ
	//しゅうりょう なされますかな?

BattleFrontier_BattleArenaBattleRoom_Text_257E9E: @ 8257E9E
FallarborTown_BattleTentBattleRoom_Text_257E9E: @ 8257E9E
	.string "연승 팀 배틀의 도전을\n"
	.string "중단할까요?$"
	//かちぬきチ-ムバトルの ちょうせんをｎ
	//ちゅうし なされますかな?

BattleFrontier_BattleArenaBattleRoom_Text_257EDB: @ 8257EDB
FallarborTown_BattleTentBattleRoom_Text_257EDB: @ 8257EDB
	.string "리포트를 작성하고 있습니다!\n"
	.string "잠시 기다려 주십시오$"
	//レポ-トを かいております!ｎ
	//しばし おまちくだされ!

BattleFrontier_BattleArenaBattleRoom_Text_257F04: @ 8257F04
	.string "지금의 승부를\n"
	.string "프런티어패스에 기록하겠습니까?$"
	//さきほどの たたかいをｎ
	//フロンティアパスに きろく されますかな?

BattleFrontier_BattleArenaBattleRoom_Text_257F45: @ 8257F45
	.string "손님!\p"
	.string "당신의 실력은\n"
	.string "실로 굉장하군요!\n"
	.string "그러니 이쯤에서 한번\n"
	.string "우리들의 대장 아레나캡틴과\l"
	.string "한 수 부탁드립니다!$"
	//$おきゃくじん!ｐ
	//あなたの じつりょくはｎ
	//じつに すさまじいで ございますな!ｐ
	//そこで ここらで ひとつｎ
	//われらが たいしょう アリ-ナキャプテンとｌ
	//おてあわせ いただき ましょう!

BattleFrontier_BattleArenaBattleRoom_Text_257FBB: @ 8257FBB
	.string "아레나캡틴과의 승부!\n"
	.string "각오는 되셨습니까?$"
	//アリ-ナキャプテンとの しょうぶ!ｎ
	//かくごの ほうは よろしい ですかな?

BattleFrontier_BattleArenaBattleRoom_Text_257FED: @ 8257FED
	.string "심판: 아레나캡틴! 나리님!\n"
	.string "입장하십니다---!$"
	//しんぱん『アリ-ナキャプテン! コゴミさま!ｎ
	//ごにゅうじょう---!

BattleFrontier_BattleArenaBattleRoom_Text_25801C: @ 825801C
	.string "나리: 네엡! 잘 부탁해-!!\p"
	.string "... 라니 당신이 도전자?$"
	//コゴミ『ウィ-ッス! よろしく-!!ｐ
	//…… って あなたが ちょうせんしゃ?

BattleFrontier_BattleArenaBattleRoom_Text_25804E: @ 825804E
	.string "흐-음... 헤-에... 헤에에에...$"
	//ふ-ん…… へ-え…… へえぇぇ……

BattleFrontier_BattleArenaBattleRoom_Text_258068: @ 8258068
	.string "뭐랄까- 솔직히 말해서\n"
	.string "은근 약할 것 같은 느낌인데-\l"
	.string "나하고 배틀해도\l"
	.string "괜찮으려나-?\p"
	.string "으으-음...\n"
	.string "뭐 좋아!\n"
	.string "곧고 가볍게 솜씨 좀 봐야겠어!$"
	//なんて いうか- しょうじき いってｎ
	//かなり よわっちい かんじ なんだけど-ｌ
	//アタシと たたかってもｌ
	//だいじょうぶ なのかな-?ｐ
	//ぅう-ん……ｐ
	//まあ いいかっ!ｎ
	//まずは かる-く おてなみ はいけんねっ!

BattleFrontier_BattleArenaBattleRoom_Text_25810D: @ 825810D
	.string "자!\n"
	.string "내 투지에 불을 붙여줘!$"
	//さあっ!ｎ
	//アタシの とうしに ひを つけてねっ!

BattleFrontier_BattleArenaBattleRoom_Text_25813F: @ 825813F
	.string "나리: 어머 잠깐만-!\n"
	.string "당신 엄청나게 강하잖아-!!\l"
	.string "마음에 들었어! 프런티어패스 줘 봐!$"
	//コゴミ『やだ ちょっと-!ｎ
	//あなた ぜんぜん つよい じゃん-!ｌ
	//きにいった! フロンティアパス かしてっ!

BattleFrontier_BattleArenaBattleRoom_Text_25819C: @ 825819C
	.string "프런티어패스에\n"
	.string "거츠심볼이 새겨졌다!$"
	//フロンティアパスにｎ
	//ガッツシンボルが きざまれた!

BattleFrontier_BattleArenaBattleRoom_Text_2581CF: @ 82581CF
	.string "으-음!\p"
	.string "다음에 만날 때가\n"
	.string "기대되기 시작했어-!$"
	//ぅう-ん!ｐ
	//つぎに あえるときがｎ
	//たのしみに なって きたな-!

BattleFrontier_BattleArenaBattleRoom_Text_258213: @ 8258213
	.string "나리: 네엡! 오랜만이네-!\n"
	.string "드디어 여기까지 이겨 왔구나!\p"
	.string "늦어서 걱정했단 말야-!\n"
	.string "당신과 만나는 걸 엄-청나게!\l"
	.string "기대하고 있었으니까-!!$"
	//コゴミ『ウィ-ッス! ごぶさた-!ｎ
	//や-っと ここまで かちぬいて きたね!ｐ
	//おそいから しんぱい しちゃったよ-っ!ｎ
	//あなたと あえるの もの すっご-くっ!ｌ
	//たのしみに してたん だからね-っ!!

BattleFrontier_BattleArenaBattleRoom_Text_2582A2: @ 82582A2
	.string "... ... ... ... 그러니까 준비됐어?$"
	//…… …… …… …… だから い-い?

BattleFrontier_BattleArenaBattleRoom_Text_2582BB: @ 82582BB
	.string "어중간한 배틀은 용서하지 않을 거야\n"
	.string "각오하고 있으라고!!$"
	//はんぱな たたかいじゃ ゆるさないっ!!ｎ
	//かくご しといてねっ!!

BattleFrontier_BattleArenaBattleRoom_Text_2582F9: @ 82582F9
	.string "이봐 심판!\n"
	.string "얼른 시작하도록 해!!$"
	//ほらっ しんぱん!ｎ
	//さっさと はじめなさいっ!!

BattleFrontier_BattleArenaBattleRoom_Text_258323: @ 8258323
	.string "나리: 아---! 정말---!!\n"
	.string "얼른 프런티어패스 줘 봐!$"
	//コゴミ『あ---っ! も---っ!!ｎ
	//さっさと フロンティアパス かしてよっ!

BattleFrontier_BattleArenaBattleRoom_Text_25835B: @ 825835B
	.string "거츠심볼이\n"
	.string "금색으로 빛났다!$"
	//ガッツシンボルがｎ
	//きんいろに かがやいた!

BattleFrontier_BattleArenaBattleRoom_Text_258383: @ 8258383
	.string "으아-아!! 분하다---아!!\p"
	.string "다음에 배틀하게 된다면\n"
	.string "절-대로 지지 않을 거얏! 바이바이!$"
	//むき-っ!! くやし---っ!!ｐ
	//こんど たたかう ことが あったらｎ
	//ぜ-ったい まけない からっ! バイバイっ!
