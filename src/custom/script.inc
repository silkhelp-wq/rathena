// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Script Commands
 * Place the body of custom script commands in this file.
 * Format:
 *	BUILDIN_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//BUILDIN_FUNC(example)
//{
//	ShowInfo("buildin_example: It works!\n");
//	script_pushint(st,1);
//	return 0;
//}

// Future RO: fro_checkpoints {<full tiers>}; - bring the attached player's free stat, trait
// and skill points to exactly what their levels allow (pc_fro_check_points). Scripts that set
// stats or skills directly call it when they are done; the Build Master passes 1 (its builds
// count every class on the way at its max job level).
BUILDIN_FUNC(fro_checkpoints)
{
	map_session_data* sd;
	if( !script_rid2sd( sd ) )
		return SCRIPT_CMD_FAILURE;
	pc_fro_check_points( sd, script_hasdata( st, 2 ) && script_getnum( st, 2 ) != 0 );
	return SCRIPT_CMD_SUCCESS;
}
