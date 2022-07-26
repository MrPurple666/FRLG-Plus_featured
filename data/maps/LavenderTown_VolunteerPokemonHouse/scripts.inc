.set LOCALID_MAROWAK_MASTER, 7
.set TRAINER, VAR_0x8009

LavenderTown_VolunteerPokemonHouse_MapScripts:: @ 816B149
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_VolunteerPokemonHouse_MapScript_SetMasterTrainerMovementTypes
	.byte 0

LavenderTown_VolunteerPokemonHouse_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MAROWAK
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq LavenderTown_VolunteerPokemonHouse_MapScript_MarowakMasterMovementType
	end

LavenderTown_VolunteerPokemonHouse_MapScript_MarowakMasterMovementType::
	setobjectmovementtype LOCALID_MAROWAK_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji:: @ 816B14A
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute:: @ 816B196
	checkitem ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_HaveOldSeaMap
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_HaveOldSeaMap::
	goto_if_set FLAG_CAUGHT_MEW, LavenderTown_VolunteerPokemonHouse_EventScript_MewEventFinished
	goto_if_set FLAG_FOUGHT_MEW, LavenderTown_VolunteerPokemonHouse_EventScript_MewCaught
	goto_if_unset FLAG_MEW_FLEW_AWAY, LavenderTown_VolunteerPokemonHouse_EventScript_MewNotEncountered
	goto_if_set FLAG_MEW_FLEW_AWAY, LavenderTown_VolunteerPokemonHouse_EventScript_MewDefeated
LavenderTown_VolunteerPokemonHouse_EventScript_MewNotEncountered:
	msgbox LavenderTown_VolunteerPokemonHouse_Text_FindFarawayIsland, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_MewFoundNo
	msgbox LavenderTown_VolunteerPokemonHouse_Text_NotEncounteredMew
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MewDefeated::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_FoundMew, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_MewFoundNo
	msgbox LavenderTown_VolunteerPokemonHouse_Text_DefeatedMew
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MewCaught::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_FoundMew, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_MewFoundNo
	msgbox LavenderTown_VolunteerPokemonHouse_Text_CaughtMew
	setflag FLAG_CAUGHT_MEW
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MewEventFinished::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HowAreYouAndMew
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MewFoundNo::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_AnsweredNo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute:: @ 816B1A0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl:: @ 816B1AA
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy:: @ 816B1C3
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster:: @ 816B1CC
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack:: @ 816B1E1
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino:: @ 816B1EB
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck:: @ 816B1FE
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine:: @ 816B211
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf:: @ 816B229
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end
