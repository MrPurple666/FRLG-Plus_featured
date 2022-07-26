.set LOCALID_MAGNETON_MASTER, 1
.set LOCALID_MAGNEMITE_MASTER, 2
.set TRAINER, VAR_0x8009

UndergroundPath_NorthSouthTunnel_MapScripts:: @ 8160EB5
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundPath_NorthSouthTunnel_OnTransition
	.byte 0

UndergroundPath_NorthSouthTunnel_OnTransition:: @ 8160EBB
	setworldmapflag FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL
	goto UndergroundPath_NorthSouthTunnel_MapScript_SetMasterTrainerMovementTypes
	end

UndergroundPath_NorthSouthTunnel_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MAGNEMITE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq UndergroundPath_NorthSouthTunnel_MapScript_MagnemiteMasterMovementType
	setvar TRAINER, MASTER_MAGNETON
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq UndergroundPath_NorthSouthTunnel_MapScript_MagnetonMasterMovementType
	end

UndergroundPath_NorthSouthTunnel_MapScript_MagnemiteMasterMovementType::
	setobjectmovementtype LOCALID_MAGNEMITE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
	
UndergroundPath_NorthSouthTunnel_MapScript_MagnetonMasterMovementType::
	setobjectmovementtype LOCALID_MAGNETON_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return