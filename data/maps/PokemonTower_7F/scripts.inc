.set LOCALID_GRUNT1, 2
.set LOCALID_GRUNT2, 3
.set LOCALID_GRUNT3, 4
.set LOCALID_WEEPINBELL_MASTER, 5
.set TRAINER, VAR_0x8009

PokemonTower_7F_MapScripts:: @ 8163559
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_7F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonTower_7F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_WEEPINBELL
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PokemonTower_7F_MapScript_WeepinbellMasterMovementType
	end

PokemonTower_7F_MapScript_WeepinbellMasterMovementType::
	setobjectmovementtype LOCALID_WEEPINBELL_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PokemonTower_7F_EventScript_MrFuji:: @ 816355A
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	setflag FLAG_HIDE_TOWER_FUJI
	clearflag FLAG_HIDE_POKEHOUSE_FUJI
	setflag FLAG_RESCUED_MR_FUJI
	msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe
	closemessage
	warp MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, 255, 4, 7
	waitstate
	release
	end

PokemonTower_7F_EventScript_Grunt1:: @ 8163586
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_19, PokemonTower_7F_Text_Grunt1Intro, PokemonTower_7F_Text_Grunt1Defeat, PokemonTower_7F_EventScript_DefeatedGrunt1
	msgbox PokemonTower_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt1:: @ 81635A1
	msgbox PokemonTower_7F_Text_Grunt1PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitMid
	compare VAR_0x8004, 11
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitLeft
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitMid:: @ 81635E0
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitMid
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitRight:: @ 81635F0
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitLeft:: @ 8163600
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitLeft
	waitmovement 0
	playse SE_EXIT
	delay 25
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_RemoveGrunt1:: @ 8163616
	removeobject LOCALID_GRUNT1
	release
	end

PokemonTower_7F_Movement_Grunt1ExitMid:: @ 816361B
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitRight:: @ 8163624
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1Exit:: @ 816362C
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitLeft:: @ 8163633
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

PokemonTower_7F_EventScript_Grunt2:: @ 816363D
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_20, PokemonTower_7F_Text_Grunt2Intro, PokemonTower_7F_Text_Grunt2Defeat, PokemonTower_7F_EventScript_DefeatedGrunt2
	msgbox PokemonTower_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt2:: @ 8163658
	famechecker FAMECHECKER_MRFUJI, 1
	msgbox PokemonTower_7F_Text_Grunt2PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitLeft
	compare VAR_0x8004, 13
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitRight
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitLeft:: @ 8163699
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitRight:: @ 81636A9
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_RemoveGrunt2:: @ 81636B9
	removeobject LOCALID_GRUNT2
	release
	end

PokemonTower_7F_Movement_Grunt2ExitLeft:: @ 81636BE
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2Exit:: @ 81636C6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2ExitRight:: @ 81636CD
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_EventScript_Grunt3:: @ 81636D6
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_21, PokemonTower_7F_Text_Grunt3Intro, PokemonTower_7F_Text_Grunt3Defeat, PokemonTower_7F_EventScript_DefeatedGrunt3
	msgbox PokemonTower_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt3:: @ 81636F1
	msgbox PokemonTower_7F_Text_Grunt3PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitLeft
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitRight:: @ 8163725
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitLeft:: @ 8163735
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_RemoveGrunt3:: @ 8163745
	removeobject LOCALID_GRUNT3
	release
	end

PokemonTower_7F_EventScript_Unused:: @ 816374A
	release
	end

PokemonTower_7F_Movement_Grunt3ExitRight:: @ 816374C
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3Exit:: @ 8163754
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3ExitLeft:: @ 816375B
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
