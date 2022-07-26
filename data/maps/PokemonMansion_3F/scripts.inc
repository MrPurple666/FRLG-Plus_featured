.set LOCALID_DITTO_MASTER, 5
.set TRAINER, VAR_0x8009

PokemonMansion_3F_MapScripts:: @ 81622A1
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_3F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonMansion_3F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_DITTO
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PokemonMansion_3F_MapScript_DittoMasterMovementType
	end

PokemonMansion_3F_MapScript_DittoMasterMovementType::
	setobjectmovementtype LOCALID_DITTO_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PokemonMansion_3F_OnLoad:: @ 81622A7
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue:: @ 81622B1
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th:: @ 81622C5
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon:: @ 81622CE
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon:: @ 81622E5
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end
