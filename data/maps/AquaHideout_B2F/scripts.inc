AquaHideout_B2F_MapScripts:: @ 8233DCF
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition: @ 8233DD5
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing:: @ 8233DDF
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer:: @ 8233DE5
	lockall
	setvar VAR_0x8008, 1  @ Matt object event id
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt:: @ 8233E09
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape:: @ 8233E25
	setvar VAR_0x8008, 1  @ Matt object event id
	setvar VAR_0x8009, 4  @ Submarine object event id
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFastestLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft: @ 8233E80
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight: @ 8233E85
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4:: @ 8233E8A
	trainerbattle_single TRAINER_GRUNT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated:: @ 8233EA5
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt22:: @ 8233EAF
	trainerbattle_single TRAINER_GRUNT_22, AquaHideout_B2F_Text_Grunt22Intro, AquaHideout_B2F_Text_Grunt22Defeat
	msgbox AquaHideout_B2F_Text_Grunt22PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt26:: @ 8233EC6
	trainerbattle_single TRAINER_GRUNT_26, AquaHideout_B2F_Text_Grunt26Intro, AquaHideout_B2F_Text_Grunt26Defeat
	msgbox AquaHideout_B2F_Text_Grunt26PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro: @ 8233EDD
	.string "우효효...\p"
	.string "이미 여기까지 온 건가!\n"
	.string "생각한 것보다 강한데!\p"
	.string "하지만 여기까지다!\p"
	.string "난 여태까지의 조무래기들과는\n"
	.string "전혀 다르다!\p"
	.string "시간벌기 따윈 하지 않고\n"
	.string "널 짓밟아 주지!$"
	//ウヒョヒョ……ｐ
	//もう ここまで きたのか!ｎ
	//おもって いたより やるな!ｐ
	//だが ここまでだ!ｎ
	//おれは これまでの したっぱども とはｌ
	//ひとあじ ちがう!ｐ
	//じかんかせぎ なんか しねえでｎ
	//おまえを コテンパンに してやるぜ!

AquaHideout_B2F_Text_MattDefeat: @ 8233F8D
	.string "우효효...\n"
	.string "져버렸나...$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations: @ 8233FA6
	.string "우효효!\p"
	.string "나하고 승부하는 사이에\n"
	.string "지금쯤 리더는\l"
	.string "목적을 달성하셨을 거다!$"

AquaHideout_B2F_Text_MattPostBattle: @ 8233FF2
	.string "우효효!\p"
	.string "리더는 이미 바닷속 깊은 곳의\n"
	.string "동굴에 도착하셨을 거다!\p"
	.string "리더를 쫓으려면\n"
	.string "해안시티 너머의 그 넓은 바다를\l"
	.string "돌아다녀야 할 걸?\p"
	.string "리더를 찾을 수 있을까...\n"
	.string "우효효!$"

AquaHideout_B2F_Text_Grunt4Intro: @ 82340B4
	.string "왓핫핫 기다리다\n"
	.string "목이 빠지는 줄 알았다!\l"
	.string "나랑도 승부해 주실까?!$"

AquaHideout_B2F_Text_Grunt4Defeat: @ 82340F0
	.string "기다리다 너무 지쳐서\n"
	.string "져버렸다...$"

AquaHideout_B2F_Text_Grunt4PostBattle: @ 8234112
	.string "리더...\n"
	.string "이 정도면 된 건가요-?!$"

AquaHideout_B2F_Text_Grunt22Intro: @ 823412D
	.string "우리 아지트의 명물인 워프패널!\p"
	.string "지금 자신이 어디에 있는지\n"
	.string "전혀 짐작도 안 가겠죠?!\p"
	.string "그렇게 상대를 지치게 해서\n"
	.string "쓰러뜨리는 게 작전인 거예요!$"

AquaHideout_B2F_Text_Grunt22Defeat: @ 82341CE
	.string "뭐얏!\n"
	.string "하나도 안 지쳐 있잖아?!$"

AquaHideout_B2F_Text_Grunt22PostBattle: @ 82341FE
	.string "그러고 보니... 마스터볼을\n"
	.string "어디에 뒀었는지 까먹었어\p"
	.string "그걸 지키고 있지 않으면\n"
	.string "리더에게 혼이 난다구...$"

AquaHideout_B2F_Text_Grunt26Intro: @ 823426F
	.string "내가 아쿠아단에 들어와서\n"
	.string "가장 먼저 배운 게\l"
	.string "이 워프패널의 배열이다!$"
	//オレが アクアだんに はいってｎ
	//まっさきに おぼえ させられたのがｌ
	//この ワ-プパネルの はいれつだ!

AquaHideout_B2F_Text_Grunt26Defeat: @ 82342CC
	.string "워프패널에 대한 걸로\n"
	.string "머리가 가득 차서...$"
	//ワ-プパネルの ことでｎ
	//あたまが いっぱい だったから……

AquaHideout_B2F_Text_Grunt26PostBattle: @ 82342FF
	.string "이제부터는 포켓몬 승부의\n"
	.string "요령도 배워둬야겠다...$"
	//これからは ポケモンしょうぶのｎ
	//コツも おぼえて おかないと なあ……
