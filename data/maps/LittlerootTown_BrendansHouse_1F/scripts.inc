LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
	setobjectxyperm 1, 8, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
	setobjectxyperm 1, 4, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
	setobjectxyperm 1, 9, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
	lockall
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1  @ Object event ID for Mom
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
	lockall
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_BOY_SUP, 1
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement 7, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
	.string "엄마: {PLAYER}{K_AYA} 봐 보렴\n"
	.string "집 안도 멋지지 않니?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
	.string "집 안 정리를\n"
	.string "이삿짐센터 포켓몬이 도와주니까\l"
	.string "이렇게 편할 수가 없어!\p"
	.string "{PLAYER}도 2층에 있는\n"
	.string "네 방에 한번 가보렴!\p"
	.string "아빠가 이사 기념으로\n"
	.string "사 주신 시계가 있을 거니까\l"
	.string "시간 좀 맞춰 둬$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
	.string "엄마: {PLAYER}\p"
	.string "네 방은 안 봐도 되니?$"

PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
	.string "엄마: {PLAYER}\n"
	.string "방 안에 있는 시계 좀 맞춰줄래?$"

PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
	.string "엄마: ...아! {PLAYER}! {PLAYER}!\n"
	.string "이리로 빨리 와보렴!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
	.string "엄마: 등화도시 체육관이 나오고 있어\n"
	.string "아빠가 나올지도 몰라!!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
	.string "엄마: 어머... 끝나버렸네\p"
	.string "아빠가 나왔던 거 같은데\n"
	.string "아쉽네$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
	.string "...아 맞다 맞다! 이 마을에\n"
	.string "털보박사님이라고 하시는\l"
	.string "아빠 친구분이 계시거든\p"
	.string "박사님 집은 옆집이니까\n"
	.string "얼른 인사 드리고 오렴!$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
	.string "엄마: 그럼 다녀오렴!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
	.string "엄마: 어머? 털보박사님은\n"
	.string "잘 만나 뵙고 왔니?$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "엄마: 어떠니? {PLAYER}\n"
	.string "조금 지쳐 보이네?\p"
	.string "집에서 좀 쉬다 가렴$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "엄마: 그럼 조심하고!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
	.string "엄마: 어머 그 배지\n"
	.string "아빠한테 받은 거니!?\p"
	.string "그럼 엄마도 이거 줘야겠다$"

PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
	.string "너무 무리하지는 마렴\n"
	.string "언제든지 집에 와도 되니까!\p"
	.string "그럼 힘내!$"

PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
	.string "엄마: 그건 뭐니? 포켓내비?\n"
	.string "데봉의 직원에게서 받은 거니?\p"
	.string "그럼 엄마의 것도\n"
	.string "등록해둘까나!\p"
	.string "... ... ...$"
	//ママ『なあに それ? ポケナビ?ｎ
	//デボンの ひとから いただいたの?ｐ
	//じゃあ ママの こともｎ
	//とうろくして もらっちゃおうかな!
	//ｐ…… …… ……

PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
	.string "엄마를\n"
	.string "포켓내비에 등록했다!$"
	//ママをｎ
	//ポケナビに とうろく した!

PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
	.string "후기-잇$"

PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
	.string "후곳 후고 후고...$"

PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
	.string "인터뷰어: ...이상으로\n"
	.string "등화도시 체육관 앞에서\l"
	.string "전해드렸습니다!$"

PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
	.string "TV에서 영화를 하고 있다!\p"
	.string "어른과 아이가 같이\n"
	.string "커다란 피아노 위에서 춤추고 있다!\p"
	.string "빨리 가자!$"

PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
	.string "러닝슈즈의 사용설명서다!\p"
	.string "“러닝슈즈는\n"
	.string "  B 버튼을 누르면 지금보다\l"
	.string "  빨리 달릴 수 있게 해줍니다!\p"
	.string "  러닝슈즈를 신고\n"
	.string "  마음껏 달립시다!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
	.string "아빠: 응?\p"
	.string "{PLAYER} 아니냐!\p"
	.string "오랜만에 보는데\n"
	.string "어딘지 모르게 늠름해진 거 같은...\l"
	.string "그런 느낌이 드는구나\p"
	.string "그렇지만 나도\n"
	.string "아직까진 팔팔하다고\p"
	.string "...아 그래 맞다\n"
	.string "네 앞으로 하기라는 사람한테서\l"
	.string "이게 도착했어!.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
	.string "아빠: 승선티켓이구나...\p"
	.string "분명 배를 타는 선착장은\n"
	.string "잿빛도시 또는 해안시티에 있었지$"

PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
	.string "그럼 난\n"
	.string "등화도시 체육관에 돌아갈게\p"
	.string "여보\n"
	.string "그럼 다녀올게$"

PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
	.string "엄마: 네 아빠는 정말\n"
	.string "일밖에 모르는 사람이야\p"
	.string "오랜만에 집에 왔지만\n"
	.string "결국 포켓몬 얘기밖에 하지 않았단다\p"
	.string "가끔은 집에서\n"
	.string "천천히 쉬었다 가면 좋을 텐데!$"

PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
	.string "엄마: 뭔가 뉴스인 건가?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
	.string "임시 뉴스입니다\p"
	.string "호연지방 각지에서\n"
	.string "...색의 포켓몬이 날아다니는 걸\l"
	.string "봤다는 정보가 들어왔습니다\p"
	.string "아직까지 정체는\n"
	.string "확인하지 못했다고 합니다...\p"
	.string "그럼 계속 이어지는\n"
	.string "영화를 즐겨주십시오$"
	//りんじ ニュ-ス ですｐ
	//ホウエンちほうの かくちでｎ
	//……いろの ポケモンが とんでいたｌ
	//という じょうほうが よせられていますｐ
	//いまのところ しょうたいはｎ
	//わかって いない ようです……ｐ
	//では ひきつづきｎ
	//えいがを おたのしみ ください

PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
	.string "엄마: 저기 저기 {PLAYER}{K_AYA}\n"
	.string "지금 뉴스\l"
	.string "무슨 색의 포켓몬에 대해\l"
	.string "말하던 거였니?$"
	//ママ『ねえ ねえ {PLAYER}ｎ
	//いまの ニュ-スｌ
	//なにいろの ポケモンって いってたの?

PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
	.string "엄마: 흐음- 아직도\n"
	.string "알려지지 않은 포켓몬이 있구나$"
	//ママ『へえ- まだまだｎ
	//しられていない ポケモンは いるのねえ
