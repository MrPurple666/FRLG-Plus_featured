Route16_House_MapScripts:: @ 817014E
	.byte 0

Route16_House_EventScript_Woman:: @ 817014F
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02, 1, MUS_OBTAIN_TMHM
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02:: @ 817019B
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02:: @ 81701A5
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow:: @ 81701AF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, 0
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end
