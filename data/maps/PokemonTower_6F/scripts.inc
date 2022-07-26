.set LOCALID_RAICHU_MASTER, 6
.set TRAINER, VAR_0x8009

PokemonTower_6F_MapScripts:: @ 81634B7
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_6F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonTower_6F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_RAICHU
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PokemonTower_6F_MapScript_RaichuMasterMovementType
	end

PokemonTower_6F_MapScript_RaichuMasterMovementType::
	setobjectmovementtype LOCALID_RAICHU_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PokemonTower_6F_EventScript_MarowakGhost:: @ 81634B8
	lockall
	textcolor 2
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	goto_if_questlog EventScript_ReleaseEnd
	setwildbattle SPECIES_MAROWAK, 30, ITEM_NONE
	special StartMarowakBattle
	waitstate
	special QuestLog_CutRecording
	compare VAR_RESULT, FALSE  @ Set by CB2_EndMarowakBattle
	goto_if_eq PokemonTower_6F_EventScript_DefeatedMarowakGhost
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost:: @ 81634F5
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, 0
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp:: @ 8163512
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica:: @ 8163514
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia:: @ 816352B
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer:: @ 8163542
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end
