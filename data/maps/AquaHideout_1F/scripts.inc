AquaHideout_1F_MapScripts:: @ 8233493
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1:: @ 8233494
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1:: @ 82334B2
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1:: @ 82334BC
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2:: @ 82334C6
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2:: @ 82334E4
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2:: @ 82334EE
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1:: @ 82334F8
	trainerbattle_single TRAINER_GRUNT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated:: @ 8233513
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething: @ 823351D
	.string "뭐야 뭐야!\n"
	.string "우리 아쿠아단한테 무슨 볼일이야!\p"
	.string "리더라면 지금 중요한 물건을\n"
	.string "빼앗으러 가서 여기엔 없어!\p"
	.string "...어디 갔냐고?\p"
	.string "와하하하! 그런 중요한 정보를\n"
	.string "내가 알려줄 거 같으냐!$"
	//なんだ なんだ!ｎ
	//おれたち アクアだんに なんの ようだ!ｐ
	//リ-ダ-だったら いま だいじな ものをｎ
	//ぶんどりに でかけていて るすだぞ!ｐ
	//……どこに いったのか だって?ｐ
	//わはははっ!
	//そんな だいじな ことをｎ
	//おしえられる わけ ないだろうが!

AquaHideout_1F_Text_WhereMightMagmaHideoutBe: @ 82335E3
	.string "뭐야 뭐야!\n"
	.string "너 마그마단의 조무래기냐?!\p"
	.string "마그마단 놈들 아지트에서\n"
	.string "굉장한 포켓몬을\l"
	.string "눈뜨게 할 건가 봐!\p"
	.string "에-잇! 아지트는\n"
	.string "대체 어디에 있는 거야!$"
	//なんだ なんだ!ｎ
	//おまえは マグマだんの したっぱか!?ｐ
	//マグマだんめ アジトで すごいポケモンをｎ
	//めざめさせる つもり らしいな!ｐ
	//え-い! アジトはｎ
	//いったい どこに あるって いうんだ!

AquaHideout_1F_Text_BossWentToJackASubmarine: @ 823367D
	.string "뭐야 뭐야!\n"
	.string "우리 아쿠아단한테 무슨 볼일이야!\p"
	.string "리더라면 지금 잠수정을\n"
	.string "빼앗으러 가서 여기엔 없어!\p"
	.string "...어디 갔냐고?\p"
	.string "와하하하! 그런 중요한 정보를\n"
	.string "내가 알려줄 거 같으냐!$"
	//なんだ なんだ!ｎ
	//おれたち アクアだんに なんの ようだ!ｐ
	//リ-ダ-だったら いま せんすいていをｎ
	//ぶんどりに でかけていて るすだぞ!ｐ
	//……どこに いったのか だって?ｐ
	//わはははっ! そんな だいじな ことをｎ
	//おしえられる わけ ないだろうが!

AquaHideout_1F_Text_BossIsOnRoute122: @ 8233739
	.string "뭐야 뭐야!\n"
	.string "우리 아쿠아단한테 무슨 볼일이야!\p"
	.string "리더라면 지금 122번 수로에 있는\n"
	.string "송화산으로 가고 있어서 여긴 없어\p"
	.string "...뭐 하러 갔냐고?\n"
	.string "아하하하! 그런 중요한 정보를\n"
	.string "내가 알려줄 거 같으냐!$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney: @ 82337FA
	.string "뭐야 뭐야!\n"
	.string "너 마그마단의 조무래기냐?!\p"
	.string "굴뚝산에는 마그마단이 노리는\n"
	.string "굉장한 포켓몬이 있나 봐!\p"
	.string "에-잇! 그건\n"
	.string "대체 무슨 포켓몬인 거지?$"
	//なんだ なんだ!ｎ
	//おまえは マグマだんの したっぱか!?ｐ
	//えんとつやまには マグマだんが ねらうｎ
	//すごい ポケモンが いるらしいな!ｐ
	//え-い! そいつはｎ
	//いったい どんな ポケモン なんだ!

AquaHideout_1F_Text_BossIsInSlateportCity: @ 8233884
	.string "뭐야 뭐야!\n"
	.string "우리 아쿠아단한테 무슨 볼일이야!\p"
	.string "리더라면 지금 잿빛도시로\n"
	.string "가고 있어서 여기엔 없어!\p"
	.string "... ...뭐 하러 갔냐고?\n"
	.string "아하하하! 그런 중요한 정보를\n"
	.string "내가 알려줄 거 같으냐!$"

AquaHideout_1F_Text_Grunt1Intro: @ 823393D
	.string "야야얏!\n"
	.string "수상한 인물 발-견!$"

AquaHideout_1F_Text_Grunt1Defeat: @ 8233964
	.string "으-음 져버렸군-!$"

AquaHideout_1F_Text_Grunt1PostBattle: @ 8233977
	.string "승부에서는 졌지만\n"
	.string "나는 임무를 달성했다...$"
