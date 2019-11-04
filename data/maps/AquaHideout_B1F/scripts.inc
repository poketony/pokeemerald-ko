AquaHideout_B1F_MapScripts:: @ 82339A7
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume: @ 82339B2
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode:: @ 82339BC
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition: @ 82339D0
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1:: @ 82339E3
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2:: @ 82339E7
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1:: @ 82339EB
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1:: @ 8233A2F
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2:: @ 8233A38
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2:: @ 8233A7C
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2:: @ 8233A85
	trainerbattle_single TRAINER_GRUNT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated:: @ 8233AA0
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3:: @ 8233AB0
	trainerbattle_single TRAINER_GRUNT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated:: @ 8233ACB
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt21:: @ 8233AD5
	trainerbattle_single TRAINER_GRUNT_21, AquaHideout_B1F_Text_Grunt21Intro, AquaHideout_B1F_Text_Grunt21Defeat
	msgbox AquaHideout_B1F_Text_Grunt21PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt25:: @ 8233AEC
	trainerbattle_single TRAINER_GRUNT_25, AquaHideout_B1F_Text_Grunt25Intro, AquaHideout_B1F_Text_Grunt25Defeat
	msgbox AquaHideout_B1F_Text_Grunt25PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro: @ 8233B03
	.string "아지트의 비밀을 알고 싶으면\n"
	.string "이 몸을 쓰려뜨려 보시지!$"

AquaHideout_B1F_Text_Grunt2Defeat: @ 8233B4A
	.string "절대 이길 수 없을 것 같습니다...!$"

AquaHideout_B1F_Text_Grunt2PostBattle: @ 8233B5E
	.string "아지트의 비밀?\p"
	.string "그건 말이지... 가장 안쪽에\n"
	.string "잠수정이 있다는 거야!\p"
	.string "하지만 지금쯤...\n"
	.string "이히히...!$"

AquaHideout_B1F_Text_Grunt3Intro: @ 8233BC5
	.string "연료 보급 OK!\n"
	.string "과자 보급도 OK!\p"
	.string "남은 건\n"
	.string "방해꾼을 처치하는 것뿐이군!$"

AquaHideout_B1F_Text_Grunt3Defeat: @ 8233C27
	.string "제대로 당했다-앗!$"

AquaHideout_B1F_Text_Grunt3PostBattle: @ 8233C41
	.string "흥! 이제 됐어!\p"
	.string "널 방해하는 게\n"
	.string "내 임무였으니까$"

AquaHideout_B1F_Text_Grunt21Intro: @ 8233C89
	.string "하-앙 아지트를 지키고 있는 것도\n"
	.string "너무 지루하니까 상대해줄게용-$"

AquaHideout_B1F_Text_Grunt21Defeat: @ 8233CCA
	.string "하-앙 져버렸어용-$"

AquaHideout_B1F_Text_Grunt21PostBattle: @ 8233CDC
	.string "너무 종종걸음으로 돌아다니면\n"
	.string "다른 아쿠아단에게 당할지도 몰라용-$"

AquaHideout_B1F_Text_Grunt25Intro: @ 8233D1B
	.string "잠깐 거기 당신!\p"
	.string "아쿠아단과 마그마단의 유니폼\n"
	.string "어느 쪽이 멋있다고 생각해?$"
	//$ちょっと そこの あんた!ｐ
	//アクアだんと マグマだんの ユニフォ-ムｎ
	//どっちが かっこいいと おもう?
	
AquaHideout_B1F_Text_Grunt25Defeat: @ 8233D6E
	.string "보기 좋게 당했네...$"
	//かっこよく まけたわ……
	
AquaHideout_B1F_Text_Grunt25PostBattle: @ 8233D84
	.string "유니폼이 멋있으면\n"
	.string "승부에서 져도 보기 좋지 않아?$"
	//ユニフォ-ムが かっこいいとｎ
	//しょうぶに まけても えになる でしょ?
