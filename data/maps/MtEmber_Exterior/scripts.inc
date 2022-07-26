.set LOCALID_GRUNT1, 2
.set LOCALID_GRUNT2, 3

MtEmber_Exterior_MapScripts:: @ 8163946
	map_script MAP_SCRIPT_ON_RESUME, MtEmber_Exterior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtEmber_Exterior_OnTransition:: @ 8163951
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	compare VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	call_if_eq MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown:: @ 8163960
	setobjectmovementtype LOCALID_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad:: @ 8163969
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	call_if_ge MtEmber_Exterior_EventScript_OpenCave
	call_if_set FLAG_MT_EMBER_BOULDER_SHORTCUTS, MtEmber_Exterior_EventScript_MoveBoulders
	end

MtEmber_Exterior_EventScript_OpenCave:: @ 8163975
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_MoveBoulders::
	setobjectxyperm 9, 17, 45
	setobjectxyperm 10, 13, 46
	setvar VAR_TEMP_0, 1
	return

MtEmber_Exterior_EventScript_Grunt1:: @ 816397F
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	goto_if_eq MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated:: @ 816399E
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1:: @ 81639A8
	applymovement LOCALID_GRUNT1, Movement_FacePlayer
	waitmovement 0
	playbgm MUS_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts:: @ 81639DB
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadescreen FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2:: @ 81639F0
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	goto_if_eq MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_GRUNT2, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2:: @ 8163A1B
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2:: @ 8163A25
	playbgm MUS_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene:: @ 8163A4E
	lockall
	textcolor 0
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_GRUNT2, Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_GRUNT1, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GRUNT1, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT1, Movement_Delay48
	waitmovement 0
	applymovement LOCALID_GRUNT2, Movement_WalkInPlaceFastestDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan:: @ 8163AB4
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth:: @ 8163ACB
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn:: @ 8163AE2
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_BoulderShortcutTriggers::
	setflag FLAG_MT_EMBER_BOULDER_SHORTCUTS
	setvar VAR_TEMP_0, 1
	release
	end
