////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObjectAI.h"
#include "Spell.h"

/*######
## go_cat_figurine
######*/

enum CatFigurine
{
    SPELL_SUMMON_GHOST_SABER    = 5968
};

class go_cat_figurine : public GameObjectScript
{
public:
    go_cat_figurine() : GameObjectScript("go_cat_figurine") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        player->CastSpell(player, SPELL_SUMMON_GHOST_SABER, true);
        return false;
    }
};

/*######
## go_crystal_pylons (3x)
######*/
class go_northern_crystal_pylon : public GameObjectScript
{
public:
    go_northern_crystal_pylon() : GameObjectScript("go_northern_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4285) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4285);

        return true;
    }
};

class go_eastern_crystal_pylon : public GameObjectScript
{
public:
    go_eastern_crystal_pylon() : GameObjectScript("go_eastern_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4287) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4287);

        return true;
    }
};

class go_western_crystal_pylon : public GameObjectScript
{
public:
    go_western_crystal_pylon() : GameObjectScript("go_western_crystal_pylon") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
        {
            player->PrepareQuestMenu(go->GetGUID());
            player->SendPreparedQuest(go->GetGUID());
        }

        if (player->GetQuestStatus(4288) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(4288);

        return true;
    }
};

/*######
## go_barov_journal
######*/

class go_barov_journal : public GameObjectScript
{
public:
    go_barov_journal() : GameObjectScript("go_barov_journal") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_TAILORING) && player->GetBaseSkillValue(SKILL_TAILORING) >= 280 && !player->HasSpell(26086))
            player->CastSpell(player, 26095, false);

        return true;
    }
};

/*######
## go_field_repair_bot_74A
######*/

class go_field_repair_bot_74A : public GameObjectScript
{
public:
    go_field_repair_bot_74A() : GameObjectScript("go_field_repair_bot_74A") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_ENGINEERING) && player->GetBaseSkillValue(SKILL_ENGINEERING) >= 300 && !player->HasSpell(22704))
            player->CastSpell(player, 22864, false);

        return true;
    }
};

/*######
## go_gilded_brazier (Paladin First Trail quest (9678))
######*/

enum GildedBrazier
{
    NPC_STILLBLADE  = 17716
};

class go_gilded_brazier : public GameObjectScript
{
public:
    go_gilded_brazier() : GameObjectScript("go_gilded_brazier") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        {
            if (player->GetQuestStatus(9678) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* Stillblade = player->SummonCreature(NPC_STILLBLADE, 8106.11f, -7542.06f, 151.775f, 3.02598f, TEMPSUMMON_DEAD_DESPAWN, 60000))
                    Stillblade->AI()->AttackStart(player);
            }
        }
        return true;
    }
};

/*######
## go_orb_of_command
######*/

class go_orb_of_command : public GameObjectScript
{
public:
    go_orb_of_command() : GameObjectScript("go_orb_of_command") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
		/// Teleport spell to Blackwing Lair
        player->CastSpell(player, 23460, true);
        return true;
    }
};

/*######
## go_tablet_of_madness
######*/

class go_tablet_of_madness : public GameObjectScript
{
public:
    go_tablet_of_madness() : GameObjectScript("go_tablet_of_madness") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasSkill(SKILL_ALCHEMY) && player->GetSkillValue(SKILL_ALCHEMY) >= 300 && !player->HasSpell(24266))
            player->CastSpell(player, 24267, false);

        return true;
    }
};

/*######
## go_tablet_of_the_seven
######*/

class go_tablet_of_the_seven : public GameObjectScript
{
public:
    go_tablet_of_the_seven() : GameObjectScript("go_tablet_of_the_seven") { }

    //TODO: use gossip option ("Transcript the Tablet") instead, if Trinity adds support.
    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
            return true;

        if (player->GetQuestStatus(4296) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, 15065, false);

        return true;
    }
};

/*#####
## go_jump_a_tron 183146
######*/

class go_jump_a_tron : public GameObjectScript
{
public:
    go_jump_a_tron() : GameObjectScript("go_jump_a_tron") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestStatus(10111) == QUEST_STATUS_INCOMPLETE)
            player->CastSpell(player, 33382, true);

        return true;
    }
};

/*######
## go_ethereum_prison
######*/

enum EthereumPrison
{
    SPELL_REP_LC        = 39456,
    SPELL_REP_SHAT      = 39457,
    SPELL_REP_CE        = 39460,
    SPELL_REP_CON       = 39474,
    SPELL_REP_KT        = 39475,
    SPELL_REP_SPOR      = 39476
};

const uint32 NpcPrisonEntry[] =
{
    22810, 22811, 22812, 22813, 22814, 22815,               //good guys
    20783, 20784, 20785, 20786, 20788, 20789, 20790         //bad guys
};

class go_ethereum_prison : public GameObjectScript
{
public:
    go_ethereum_prison() : GameObjectScript("go_ethereum_prison") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        int Random = rand() % (sizeof(NpcPrisonEntry) / sizeof(uint32));

        if (Creature* creature = player->SummonCreature(NpcPrisonEntry[Random], go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player),
            TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
        {
            if (!creature->IsHostileTo(player))
            {
                if (FactionTemplateEntry const* pFaction = creature->getFactionTemplateEntry())
                {
                    uint32 Spell = 0;

                    switch (pFaction->Faction)
                    {
                        case 1011: Spell = SPELL_REP_LC; break;
                        case 935: Spell = SPELL_REP_SHAT; break;
                        case 942: Spell = SPELL_REP_CE; break;
                        case 933: Spell = SPELL_REP_CON; break;
                        case 989: Spell = SPELL_REP_KT; break;
                        case 970: Spell = SPELL_REP_SPOR; break;
                    }

                    if (Spell)
                        creature->CastSpell(player, Spell, false);
                    else
                        sLog->outError(LOG_FILTER_TSCR, "go_ethereum_prison summoned Creature (entry %u) but faction (%u) are not expected by script.", creature->GetEntry(), creature->getFaction());
                }
            }
        }

        return false;
    }
};

/*######
## go_ethereum_stasis
######*/

const uint32 NpcStasisEntry[] =
{
    22825, 20888, 22827, 22826, 22828
};

class go_ethereum_stasis : public GameObjectScript
{
public:
    go_ethereum_stasis() : GameObjectScript("go_ethereum_stasis") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        int Random = rand() % (sizeof(NpcStasisEntry) / sizeof(uint32));

        player->SummonCreature(NpcStasisEntry[Random], go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player),
            TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return false;
    }
};

/*######
## go_resonite_cask
######*/

enum ResoniteCask
{
    NPC_GOGGEROC    = 11920
};

class go_resonite_cask : public GameObjectScript
{
public:
    go_resonite_cask() : GameObjectScript("go_resonite_cask") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            go->SummonCreature(NPC_GOGGEROC, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

        return false;
    }
};

/*######
## go_sacred_fire_of_life
######*/

#define NPC_ARIKARA  10882

class go_sacred_fire_of_life : public GameObjectScript
{
public:
    go_sacred_fire_of_life() : GameObjectScript("go_sacred_fire_of_life") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            player->SummonCreature(NPC_ARIKARA, -5008.338f, -2118.894f, 83.657f, 0.874f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return true;
    }
};

/*######
## go_shrine_of_the_birds
######*/

enum ShrineOfTheBirds
{
    NPC_HAWK_GUARD      = 22992,
    NPC_EAGLE_GUARD     = 22993,
    NPC_FALCON_GUARD    = 22994,
    GO_SHRINE_HAWK      = 185551,
    GO_SHRINE_EAGLE     = 185547,
    GO_SHRINE_FALCON    = 185553
};

class go_shrine_of_the_birds : public GameObjectScript
{
public:
    go_shrine_of_the_birds() : GameObjectScript("go_shrine_of_the_birds") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        uint32 BirdEntry = 0;

        float fX, fY, fZ;
        go->GetClosePoint(fX, fY, fZ, go->GetObjectSize(), INTERACTION_DISTANCE);

        switch (go->GetEntry())
        {
            case GO_SHRINE_HAWK:
                BirdEntry = NPC_HAWK_GUARD;
                break;
            case GO_SHRINE_EAGLE:
                BirdEntry = NPC_EAGLE_GUARD;
                break;
            case GO_SHRINE_FALCON:
                BirdEntry = NPC_FALCON_GUARD;
                break;
        }

        if (BirdEntry)
            player->SummonCreature(BirdEntry, fX, fY, fZ, go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);

        return false;
    }
};

/*######
## go_southfury_moonstone
######*/

enum Southfury
{
    NPC_RIZZLE                  = 23002,
    SPELL_BLACKJACK             = 39865, //stuns player
    SPELL_SUMMON_RIZZLE         = 39866
};

class go_southfury_moonstone : public GameObjectScript
{
public:
    go_southfury_moonstone() : GameObjectScript("go_southfury_moonstone") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        //implicitTarget=48 not implemented as of writing this code, and manual summon may be just ok for our purpose
        //player->CastSpell(player, SPELL_SUMMON_RIZZLE, false);

        if (Creature* creature = player->SummonCreature(NPC_RIZZLE, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0))
            creature->CastSpell(player, SPELL_BLACKJACK, false);

        return false;
    }
};

/*######
## go_tele_to_dalaran_crystal
######*/

enum DalaranCrystal
{
    QUEST_LEARN_LEAVE_RETURN    = 12790,
    QUEST_TELE_CRYSTAL_FLAG     = 12845
};

#define GO_TELE_TO_DALARAN_CRYSTAL_FAILED   "This teleport crystal cannot be used until the teleport crystal in Dalaran has been used at least once."

class go_tele_to_dalaran_crystal : public GameObjectScript
{
public:
    go_tele_to_dalaran_crystal() : GameObjectScript("go_tele_to_dalaran_crystal") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestRewardStatus(QUEST_TELE_CRYSTAL_FLAG))
            return false;

        player->GetSession()->SendNotification(GO_TELE_TO_DALARAN_CRYSTAL_FAILED);

        return true;
    }
};

/*######
## go_tele_to_violet_stand
######*/

class go_tele_to_violet_stand : public GameObjectScript
{
public:
    go_tele_to_violet_stand() : GameObjectScript("go_tele_to_violet_stand") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetQuestRewardStatus(QUEST_LEARN_LEAVE_RETURN) || player->GetQuestStatus(QUEST_LEARN_LEAVE_RETURN) == QUEST_STATUS_INCOMPLETE)
            return false;

        return true;
    }
};

/*######
## go_fel_crystalforge
######*/

#define GOSSIP_FEL_CRYSTALFORGE_TEXT 31000
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN 31001
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_1 "Purchase 1 Unstable Flask of the Beast for the cost of 10 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_5 "Purchase 5 Unstable Flask of the Beast for the cost of 50 Apexis Shards"
#define GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN "Use the fel crystalforge to make another purchase."

enum FelCrystalforge
{
    SPELL_CREATE_1_FLASK_OF_BEAST   = 40964,
    SPELL_CREATE_5_FLASK_OF_BEAST   = 40965
};

class go_fel_crystalforge : public GameObjectScript
{
public:
    go_fel_crystalforge() : GameObjectScript("go_fel_crystalforge") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER) /* != GAMEOBJECT_TYPE_QUESTGIVER) */
            player->PrepareQuestMenu(go->GetGUID()); /* return true*/

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, go->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->CastSpell(player, SPELL_CREATE_1_FLASK_OF_BEAST, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CastSpell(player, SPELL_CREATE_5_FLASK_OF_BEAST, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FEL_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(GOSSIP_FEL_CRYSTALFORGE_TEXT, go->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## go_bashir_crystalforge
######*/

#define GOSSIP_BASHIR_CRYSTALFORGE_TEXT 31100
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN 31101
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1 "Purchase 1 Unstable Flask of the Sorcerer for the cost of 10 Apexis Shards"
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5 "Purchase 5 Unstable Flask of the Sorcerer for the cost of 50 Apexis Shards"
#define GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN "Use the bashir crystalforge to make another purchase."

enum BashirCrystalforge
{
    SPELL_CREATE_1_FLASK_OF_SORCERER   = 40968,
    SPELL_CREATE_5_FLASK_OF_SORCERER   = 40970
};

class go_bashir_crystalforge : public GameObjectScript
{
public:
    go_bashir_crystalforge() : GameObjectScript("go_bashir_crystalforge") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER) /* != GAMEOBJECT_TYPE_QUESTGIVER) */
            player->PrepareQuestMenu(go->GetGUID()); /* return true*/

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_TEXT, go->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->CastSpell(player, SPELL_CREATE_1_FLASK_OF_SORCERER, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->CastSpell(player, SPELL_CREATE_5_FLASK_OF_SORCERER, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_RETURN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_ITEM_TEXT_RETURN, go->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BASHIR_CRYSTALFORGE_ITEM_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(GOSSIP_BASHIR_CRYSTALFORGE_TEXT, go->GetGUID());
                break;
        }
        return true;
    }
};

/*######
## matrix_punchograph
######*/

enum MatrixPunchograph
{
    ITEM_WHITE_PUNCH_CARD = 9279,
    ITEM_YELLOW_PUNCH_CARD = 9280,
    ITEM_BLUE_PUNCH_CARD = 9282,
    ITEM_RED_PUNCH_CARD = 9281,
    ITEM_PRISMATIC_PUNCH_CARD = 9316,
    SPELL_YELLOW_PUNCH_CARD = 11512,
    SPELL_BLUE_PUNCH_CARD = 11525,
    SPELL_RED_PUNCH_CARD = 11528,
    SPELL_PRISMATIC_PUNCH_CARD = 11545,
    MATRIX_PUNCHOGRAPH_3005_A = 142345,
    MATRIX_PUNCHOGRAPH_3005_B = 142475,
    MATRIX_PUNCHOGRAPH_3005_C = 142476,
    MATRIX_PUNCHOGRAPH_3005_D = 142696
};

class go_matrix_punchograph : public GameObjectScript
{
public:
    go_matrix_punchograph() : GameObjectScript("go_matrix_punchograph") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        switch (go->GetEntry())
        {
            case MATRIX_PUNCHOGRAPH_3005_A:
                if (player->HasItemCount(ITEM_WHITE_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_WHITE_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_YELLOW_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_B:
                if (player->HasItemCount(ITEM_YELLOW_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_YELLOW_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_BLUE_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_C:
                if (player->HasItemCount(ITEM_BLUE_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_BLUE_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_RED_PUNCH_CARD, true);
                }
                break;
            case MATRIX_PUNCHOGRAPH_3005_D:
                if (player->HasItemCount(ITEM_RED_PUNCH_CARD))
                {
                    player->DestroyItemCount(ITEM_RED_PUNCH_CARD, 1, true);
                    player->CastSpell(player, SPELL_PRISMATIC_PUNCH_CARD, true);
                }
                break;
            default:
                break;
        }
        return false;
    }
};

/*######
## go_scourge_cage
######*/

enum ScourgeCage
{
    NPC_SCOURGE_PRISONER = 25610
};

class go_scourge_cage : public GameObjectScript
{
public:
    go_scourge_cage() : GameObjectScript("go_scourge_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (Creature* pNearestPrisoner = go->FindNearestCreature(NPC_SCOURGE_PRISONER, 5.0f, true))
        {
            go->SetGoState(GO_STATE_ACTIVE);
            player->KilledMonsterCredit(NPC_SCOURGE_PRISONER, pNearestPrisoner->GetGUID());
            pNearestPrisoner->DisappearAndDie();
        }

        return true;
    }
};

/*######
## go_arcane_prison
######*/

enum ArcanePrison
{
    QUEST_PRISON_BREAK                  = 11587,
    SPELL_ARCANE_PRISONER_KILL_CREDIT   = 45456
};

class go_arcane_prison : public GameObjectScript
{
public:
    go_arcane_prison() : GameObjectScript("go_arcane_prison") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_PRISON_BREAK) == QUEST_STATUS_INCOMPLETE)
        {
            go->SummonCreature(25318, 3485.089844f, 6115.7422188f, 70.966812f, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
            player->CastSpell(player, SPELL_ARCANE_PRISONER_KILL_CREDIT, true);
            return true;
        }
        return false;
    }
};

/*######
## go_blood_filled_orb
######*/

#define NPC_ZELEMAR  17830

class go_blood_filled_orb : public GameObjectScript
{
public:
    go_blood_filled_orb() : GameObjectScript("go_blood_filled_orb") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            player->SummonCreature(NPC_ZELEMAR, -369.746f, 166.759f, -21.50f, 5.235f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);

        return true;
    }
};

/*######
## go_jotunheim_cage
######*/

enum JotunheimCage
{
    NPC_EBON_BLADE_PRISONER_HUMAN   = 30186,
    NPC_EBON_BLADE_PRISONER_NE      = 30194,
    NPC_EBON_BLADE_PRISONER_TROLL   = 30196,
    NPC_EBON_BLADE_PRISONER_ORC     = 30195,

    SPELL_SUMMON_BLADE_KNIGHT_H     = 56207,
    SPELL_SUMMON_BLADE_KNIGHT_NE    = 56209,
    SPELL_SUMMON_BLADE_KNIGHT_ORC   = 56212,
    SPELL_SUMMON_BLADE_KNIGHT_TROLL = 56214
};

class go_jotunheim_cage : public GameObjectScript
{
public:
    go_jotunheim_cage() : GameObjectScript("go_jotunheim_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        Creature* pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_HUMAN, 5.0f, true);
        if (!pPrisoner)
        {
            pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_TROLL, 5.0f, true);
            if (!pPrisoner)
            {
                pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_ORC, 5.0f, true);
                if (!pPrisoner)
                    pPrisoner = go->FindNearestCreature(NPC_EBON_BLADE_PRISONER_NE, 5.0f, true);
            }
        }
        if (!pPrisoner || !pPrisoner->isAlive())
            return false;

        pPrisoner->DisappearAndDie();
        player->KilledMonsterCredit(NPC_EBON_BLADE_PRISONER_HUMAN, 0);
        switch (pPrisoner->GetEntry())
        {
            case NPC_EBON_BLADE_PRISONER_HUMAN:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_H, true);
                break;
            case NPC_EBON_BLADE_PRISONER_NE:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_NE, true);
                break;
            case NPC_EBON_BLADE_PRISONER_TROLL:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_TROLL, true);
                break;
            case NPC_EBON_BLADE_PRISONER_ORC:
                player->CastSpell(player, SPELL_SUMMON_BLADE_KNIGHT_ORC, true);
                break;
        }
        return true;
    }
};

enum TableTheka
{
    GOSSIP_TABLE_THEKA = 1653,

    QUEST_SPIDER_GOLD = 2936
};

class go_table_theka : public GameObjectScript
{
public:
    go_table_theka() : GameObjectScript("go_table_theka") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_SPIDER_GOLD) == QUEST_STATUS_INCOMPLETE)
            player->AreaExploredOrEventHappens(QUEST_SPIDER_GOLD);

        player->SEND_GOSSIP_MENU(GOSSIP_TABLE_THEKA, go->GetGUID());

        return true;
    }
};

/*######
## go_inconspicuous_landmark
######*/

enum InconspicuousLandmark
{
    SPELL_SUMMON_PIRATES_TREASURE_AND_TRIGGER_MOB    = 11462,
    ITEM_CUERGOS_KEY                                 = 9275
};

class go_inconspicuous_landmark : public GameObjectScript
{
public:
    go_inconspicuous_landmark() : GameObjectScript("go_inconspicuous_landmark") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->HasItemCount(ITEM_CUERGOS_KEY))
            return false;

        player->CastSpell(player, SPELL_SUMMON_PIRATES_TREASURE_AND_TRIGGER_MOB, true);

        return true;
    }
};

/*######
## go_ethereal_teleport_pad
######*/

enum EtherealTeleportPad
{
    NPC_IMAGE_WIND_TRADER               = 20518,
    ITEM_TELEPORTER_POWER_PACK          = 28969
};

class go_ethereal_teleport_pad : public GameObjectScript
{
public:
    go_ethereal_teleport_pad() : GameObjectScript("go_ethereal_teleport_pad") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!player->HasItemCount(ITEM_TELEPORTER_POWER_PACK))
            return false;

        go->SummonCreature(NPC_IMAGE_WIND_TRADER, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);

        return true;
    }
};

/*######
## go_soulwell
######*/

enum SoulWellData
{
    GO_SOUL_WELL                        = 181621,
    SPELL_HEALTH_STONE                  = 23517
};

class go_soulwell : public GameObjectScript
{
    public:
        go_soulwell() : GameObjectScript("go_soulwell") { }

        struct go_soulwellAI : public GameObjectAI
        {
            go_soulwellAI(GameObject* go) : GameObjectAI(go)
            {
                _stoneId = 0;
                _stoneSpell = SPELL_HEALTH_STONE;
                if (_stoneSpell == 0) // Should never happen
                    return;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(_stoneSpell);
                if (!spellInfo)
                    return;

                _stoneId = spellInfo->Effects[EFFECT_0].ItemType;
            }

            /// Due to the fact that this GameObject triggers CMSG_GAMEOBJECT_USE
            /// _and_ CMSG_GAMEOBJECT_REPORT_USE, this GossipHello hook is called
            /// twice. The script's handling is fine as it won't remove two charges
            /// on the well. We have to find how to segregate REPORT_USE and USE.
            bool GossipHello(Player* player)
            {
                Unit* owner = go->GetOwner();
                if (_stoneSpell == 0 || _stoneId == 0)
                    return true;

                if (!owner || owner->GetTypeId() != TYPEID_PLAYER || !player->IsInSameRaidWith(owner->ToPlayer()))
                    return true;

                // Don't try to add a stone if we already have one.
                if (player->HasItemCount(_stoneId, 1))
                {
                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(_stoneSpell))
                        Spell::SendCastResult(player, spell, 0, SPELL_FAILED_TOO_MANY_OF_ITEM);
                    return true;
                }

                player->CastSpell(player, _stoneSpell, true);

                return false;
            }

        private:
            uint32 _stoneSpell;
            uint32 _stoneId;
        };

        GameObjectAI* GetAI(GameObject* go) const
        {
            return new go_soulwellAI(go);
        }
};

/*######
## Quest 11255: Prisoners of Wyrmskull
## go_dragonflayer_cage
######*/

enum PrisonersOfWyrmskull
{
    QUEST_PRISONERS_OF_WYRMSKULL                  = 11255,
    NPC_PRISONER_PRIEST                           = 24086,
    NPC_PRISONER_MAGE                             = 24088,
    NPC_PRISONER_WARRIOR                          = 24089,
    NPC_PRISONER_PALADIN                          = 24090
};

class go_dragonflayer_cage : public GameObjectScript
{
public:
    go_dragonflayer_cage() : GameObjectScript("go_dragonflayer_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_PRISONERS_OF_WYRMSKULL) != QUEST_STATUS_INCOMPLETE)
            return true;

        Creature* pPrisoner = go->FindNearestCreature(NPC_PRISONER_PRIEST, 2.0f);
        if (!pPrisoner)
        {
            pPrisoner = go->FindNearestCreature(NPC_PRISONER_MAGE, 2.0f);
            if (!pPrisoner)
            {
                pPrisoner = go->FindNearestCreature(NPC_PRISONER_WARRIOR, 2.0f);
                if (!pPrisoner)
                    pPrisoner = go->FindNearestCreature(NPC_PRISONER_PALADIN, 2.0f);
            }
        }

        if (!pPrisoner || !pPrisoner->isAlive())
            return true;

        Quest const* qInfo = sObjectMgr->GetQuestTemplate(QUEST_PRISONERS_OF_WYRMSKULL);
        if (qInfo)
        {
            //TODO: prisoner should help player for a short period of time
            player->KilledMonsterCredit(qInfo->GetQuestObjectiveXIndex(0)->ObjectID, 0);
            pPrisoner->DisappearAndDie();
        }
        return true;
    }
};

/*######
## Quest 11560: Oh Noes, the Tadpoles!
## go_tadpole_cage
######*/

enum Tadpoles
{
    QUEST_OH_NOES_THE_TADPOLES                    = 11560,
    NPC_WINTERFIN_TADPOLE                         = 25201
};

class go_tadpole_cage : public GameObjectScript
{
public:
    go_tadpole_cage() : GameObjectScript("go_tadpole_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (player->GetQuestStatus(QUEST_OH_NOES_THE_TADPOLES) == QUEST_STATUS_INCOMPLETE)
        {
            Creature* pTadpole = go->FindNearestCreature(NPC_WINTERFIN_TADPOLE, 1.0f);
            if (pTadpole)
            {
                go->UseDoorOrButton();
                pTadpole->DisappearAndDie();
                player->KilledMonsterCredit(NPC_WINTERFIN_TADPOLE, 0);
                //FIX: Summon minion tadpole
            }
        }
        return true;
    }
};

/*######
## go_amberpine_outhouse
######*/

#define GOSSIP_USE_OUTHOUSE "Use the outhouse."
#define GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND "Quest item Anderhol's Slider Cider not found."

enum AmberpineOuthouse
{
    ITEM_ANDERHOLS_SLIDER_CIDER     = 37247,
    NPC_OUTHOUSE_BUNNY              = 27326,
    QUEST_DOING_YOUR_DUTY           = 12227,
    SPELL_INDISPOSED                = 53017,
    SPELL_INDISPOSED_III            = 48341,
    SPELL_CREATE_AMBERSEEDS         = 48330,
    GOSSIP_OUTHOUSE_INUSE           = 12775,
    GOSSIP_OUTHOUSE_VACANT          = 12779
};

class go_amberpine_outhouse : public GameObjectScript
{
public:
    go_amberpine_outhouse() : GameObjectScript("go_amberpine_outhouse") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        QuestStatus status = player->GetQuestStatus(QUEST_DOING_YOUR_DUTY);
        if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_USE_OUTHOUSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(GOSSIP_OUTHOUSE_VACANT, go->GetGUID());
            return true;
        }
        else
            player->SEND_GOSSIP_MENU(GOSSIP_OUTHOUSE_INUSE, go->GetGUID());
            return true;
    }

    bool OnGossipSelect(Player* player, GameObject* go, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF +1)
        {
            player->CLOSE_GOSSIP_MENU();
            Creature* target = GetClosestCreatureWithEntry(player, NPC_OUTHOUSE_BUNNY, 3.0f);
            if (target)
            {
                target->AI()->SetData(1, player->getGender());
                go->CastSpell(target, SPELL_INDISPOSED_III);
            }
            go->CastSpell(player, SPELL_INDISPOSED);
            if (player->HasItemCount(ITEM_ANDERHOLS_SLIDER_CIDER, 1))
                go->CastSpell(player, SPELL_CREATE_AMBERSEEDS);
            return true;
        }
        else
        {
            player->CLOSE_GOSSIP_MENU();
            player->GetSession()->SendNotification(GO_ANDERHOLS_SLIDER_CIDER_NOT_FOUND);
            return false;
        }
    }
};

/*######
## Quest 1126: Hive in the Tower
## go_hive_pod
######*/

enum Hives
{
    QUEST_HIVE_IN_THE_TOWER                       = 9544,
    NPC_HIVE_AMBUSHER                             = 13301
};

class go_hive_pod : public GameObjectScript
{
public:
    go_hive_pod() : GameObjectScript("go_hive_pod") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        player->SendLoot(go->GetGUID(), LOOT_CORPSE);
        go->SummonCreature(NPC_HIVE_AMBUSHER, go->GetPositionX()+1, go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        go->SummonCreature(NPC_HIVE_AMBUSHER, go->GetPositionX(), go->GetPositionY()+1, go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        return true;
    }
};

class go_massive_seaforium_charge : public GameObjectScript
{
    public:
        go_massive_seaforium_charge() : GameObjectScript("go_massive_seaforium_charge") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            go->SetLootState(GO_JUST_DEACTIVATED);
            return true;
        }
};

/*######
## go_gjalerbron_cage
######*/

enum OfKeysAndCages
{
    QUEST_ALLIANCE_OF_KEYS_AND_CAGES    = 11231,
    QUEST_HORDE_OF_KEYS_AND_CAGES       = 11265,
    NPC_GJALERBRON_PRISONER             = 24035,
    SAY_FREE                            = 0
};

class go_gjalerbron_cage : public GameObjectScript
{
    public:
        go_gjalerbron_cage() : GameObjectScript("go_gjalerbron_cage") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if ((player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_ALLIANCE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE) ||
                (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_HORDE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE))
            {
                if (Creature* prisoner = go->FindNearestCreature(NPC_GJALERBRON_PRISONER, 5.0f))
                {
                    go->UseDoorOrButton();

                    if (player)
                        player->KilledMonsterCredit(NPC_GJALERBRON_PRISONER, 0);

                    prisoner->AI()->Talk(SAY_FREE);
                    prisoner->DespawnOrUnsummon(6000);
                }
            }
            return true;
        }
};

/*########
## go_large_gjalerbron_cage
#####*/

class go_large_gjalerbron_cage : public GameObjectScript
{
    public:
        go_large_gjalerbron_cage() : GameObjectScript("go_large_gjalerbron_cage") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if ((player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_ALLIANCE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE) ||
                (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_HORDE_OF_KEYS_AND_CAGES) == QUEST_STATUS_INCOMPLETE))
            {
                std::list<Creature*> prisonerList;
                GetCreatureListWithEntryInGrid(prisonerList, go, NPC_GJALERBRON_PRISONER, INTERACTION_DISTANCE);
                for (std::list<Creature*>::const_iterator itr = prisonerList.begin(); itr != prisonerList.end(); ++itr)
                {
                    go->UseDoorOrButton();
                    player->KilledMonsterCredit(NPC_GJALERBRON_PRISONER, (*itr)->GetGUID());
                    (*itr)->DespawnOrUnsummon(6000);
                    (*itr)->AI()->Talk(SAY_FREE);
                }
            }
            return false;
        }
};

/*########
#### go_veil_skith_cage
#####*/

enum MissingFriends
{
   QUEST_MISSING_FRIENDS    = 10852,
   NPC_CAPTIVE_CHILD        = 22314,
   SAY_FREE_0               = 0
};

class go_veil_skith_cage : public GameObjectScript
{
    public:
       go_veil_skith_cage() : GameObjectScript("go_veil_skith_cage") { }

       bool OnGossipHello(Player* player, GameObject* go)
       {
           if (player->GetQuestStatus(QUEST_MISSING_FRIENDS) == QUEST_STATUS_INCOMPLETE)
           {
               std::list<Creature*> childrenList;
               GetCreatureListWithEntryInGrid(childrenList, go, NPC_CAPTIVE_CHILD, INTERACTION_DISTANCE);
               for (std::list<Creature*>::const_iterator itr = childrenList.begin(); itr != childrenList.end(); ++itr)
               {
                   go->UseDoorOrButton();
                   player->KilledMonsterCredit(NPC_CAPTIVE_CHILD, (*itr)->GetGUID());
                   (*itr)->DespawnOrUnsummon(5000);
                   (*itr)->GetMotionMaster()->MovePoint(1, go->GetPositionX()+5, go->GetPositionY(), go->GetPositionZ());
                   (*itr)->AI()->Talk(SAY_FREE_0);
                   (*itr)->GetMotionMaster()->Clear();
               }
           }
           return false;
       }
};

/*######
## go_frostblade_shrine
######*/

enum TheCleansing
{
   QUEST_THE_CLEANSING_HORDE      = 11317,
   QUEST_THE_CLEANSING_ALLIANCE   = 11322,
   SPELL_CLEANSING_SOUL           = 43351,
   SPELL_RECENT_MEDITATION        = 61720
};

class go_frostblade_shrine : public GameObjectScript
{
public:
    go_frostblade_shrine() : GameObjectScript("go_frostblade_shrine") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!player->HasAura(SPELL_RECENT_MEDITATION))
            if (player->GetQuestStatus(QUEST_THE_CLEANSING_HORDE) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_THE_CLEANSING_ALLIANCE) == QUEST_STATUS_INCOMPLETE)
            {
                go->UseDoorOrButton(10);
                player->CastSpell(player, SPELL_CLEANSING_SOUL);
                player->SetStandState(UNIT_STAND_STATE_SIT);
            }
            return true;
    }
};

/*######
## go_midsummer_bonfire
######*/

enum MidsummerBonfire
{
    STAMP_OUT_BONFIRE_QUEST_COMPLETE    = 45458
};

class go_midsummer_bonfire : public GameObjectScript
{
public:
    go_midsummer_bonfire() : GameObjectScript("go_midsummer_bonfire") { }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 /*action*/)
    {
        player->CastSpell(player, STAMP_OUT_BONFIRE_QUEST_COMPLETE, true);
        player->CLOSE_GOSSIP_MENU();
        return false;
    }
};

class go_seaforium_charge : public GameObjectScript
{
    public:
        go_seaforium_charge() : GameObjectScript("go_seaforium_charge") { }

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            if (player->HasAura(52418))
                return true;

            return false;
        }
};

class go_mage_portal_pandaria : public GameObjectScript
{
    public:
        go_mage_portal_pandaria() : GameObjectScript("go_mage_portal_pandaria") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (go->GetEntry() == 216057) // alliance
                player->TeleportTo(870, 882.98f, 297.62f, 503.12f, 3.80f);
            else if (go->GetEntry() == 216058) // horde
                player->TeleportTo(870, 1604.37f, 920.83f, 470.63f, 0.19f);

            return true;
        }
};

// Challenge Orb - 211674
class go_challenge_orb : public GameObjectScript
{
    public:
        go_challenge_orb() : GameObjectScript("go_challenge_orb") { }

        bool OnGossipSelect(Player* p_Player, GameObject* p_GameObject, uint32 /*p_Sender*/, uint32 /*p_Action*/)
        {
            if (InstanceScript* l_Instance = p_GameObject->GetInstanceScript())
            {
                ///< Check difficulty or if Challenge is already started
                if (!l_Instance->instance->IsChallengeMode() || l_Instance->IsChallengeModeStarted())
                {
                    p_Player->PlayerTalkClass->SendCloseGossip();
                    return false;
                }

                p_GameObject->SetGoState(GO_STATE_ACTIVE);
                p_GameObject->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NODESPAWN);
                l_Instance->SetChallengeModeStarted();
                p_Player->PlayerTalkClass->SendCloseGossip();
            }

            return true;
        }
};

/*######
## go_crystal_pylons (3x)
######*/
class go_dark_iron_mole_machine_wreckage : public GameObjectScript
{
    public:
        go_dark_iron_mole_machine_wreckage() : GameObjectScript("go_dark_iron_mole_machine_wreckage") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
            {
                player->PrepareQuestMenu(go->GetGUID());
                player->SendPreparedQuest(go->GetGUID());
            }

            return true;
        }
};


/// Goblin Escape Pod - 195188
class go_goblinescapepod : public GameObjectScript
{
public:
	go_goblinescapepod() : GameObjectScript("go_goblinescapepod") { }

	enum eMisc
	{
		/// Quests
		QUEST_GOBLIN_ESCAPE_PODS_A = 14474,
		QUEST_GOBLIN_ESCAPE_PODS_H = 14001,

		/// Spells
		SUMMON_CONTROLLER			= 66136,
		SUMMON_LIVE_GOBLIN			= 66137,
		SUMMON_DEAD_GOBLIN			= 66138,
		SUMMON_GALLYWIX				= 67845,
		THERMO_FLIPPERS_VISUAL	    = 68256,
		PRINCE_AURA_CONTROLLER_AURA = 67433,

		/// Npcs
		NPC_LIVE_GOBLIN	= 34748,
		NPC_DEAD_GOBLIN = 34736,
		NPC_GALLYWIX	= 35649,
		
		/// Kill credit
		KILLCREDIT_ESCAPE_POD = 34748,
	};

	bool OnGossipHello(Player* player, GameObject* pGO)
	{
		if ((player->GetQuestStatus(QUEST_GOBLIN_ESCAPE_PODS_A) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(QUEST_GOBLIN_ESCAPE_PODS_H) == QUEST_STATUS_INCOMPLETE))
		{
			// First time you should get spell GALLWIX cast and this NPC has some speech todo about ripping player off
			if (!player->HasAura(PRINCE_AURA_CONTROLLER_AURA))
			{
				player->CastSpell(player, SUMMON_GALLYWIX, true);
				player->AddAura(PRINCE_AURA_CONTROLLER_AURA, player);
				if (Creature* Gallywix = player->FindNearestCreature(NPC_GALLYWIX, 10.0f, true))
					Gallywix->AI()->Talk(0, player->GetGUID());
			}

			uint8 r = rand() % 8;
			if (r < 2) // sometimes spawn a dead goblin and doesn't give credit..
				player->CastSpell(player, SUMMON_DEAD_GOBLIN, true);
			else
			{
				player->CastSpell(player, SUMMON_LIVE_GOBLIN, true);
				player->KilledMonsterCredit(KILLCREDIT_ESCAPE_POD);

				if (Creature* goblin = player->FindNearestCreature(NPC_LIVE_GOBLIN, 10.0f, true))
				{
					goblin->CastSpell(goblin, THERMO_FLIPPERS_VISUAL, true);
					goblin->AI()->Talk(0, player->GetGUID());
				}
			}

			pGO->Delete();
			return false;
		}
		return true;
	}

};

/// Hyjal Flameward
class go_hyjal_flameward : public GameObjectScript
{
public:
	go_hyjal_flameward() : GameObjectScript("go_hyjal_flameward") { }

	enum Id
	{
		QUEST_ENTRY_PREPPING_THE_SOIL = 25502,
		SPELL_FLAMEWARD_ACTIVATED = 75470,
		NPC_ENTRY_FLAMEWARD_ACTIVATED = 40461,
		NPC_LAVA_SURGERS = 46911
	};

	bool OnGossipHello(Player* player, GameObject* go)
	{
		if (player->GetQuestStatus(QUEST_ENTRY_PREPPING_THE_SOIL) == QUEST_STATUS_INCOMPLETE)
		{
			player->CastSpell(player, SPELL_FLAMEWARD_ACTIVATED, true);
			player->MonsterWhisper("Defend the flameward!", player->GetGUID(), true);
			player->SummonCreature(NPC_ENTRY_FLAMEWARD_ACTIVATED, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 61000);

			// Call lava surgers
			std::list<Creature*> creatures;
			GetCreatureListWithEntryInGrid(creatures, player, NPC_LAVA_SURGERS, 60.0f);
			if (!creatures.empty())
			{
				for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
					(*iter)->ToCreature()->Attack(player, true);
			}
			return false;
		}
		return true;
	}
};

#ifndef __clang_analyzer__
void AddSC_go_scripts()
{
    new go_cat_figurine;
    new go_northern_crystal_pylon;
    new go_eastern_crystal_pylon;
    new go_western_crystal_pylon;
    new go_barov_journal;
    new go_field_repair_bot_74A;
    new go_gilded_brazier;
	new go_orb_of_command;
    new go_shrine_of_the_birds;
    new go_southfury_moonstone;
    new go_tablet_of_madness;
    new go_tablet_of_the_seven;
    new go_jump_a_tron;
    new go_ethereum_prison;
    new go_ethereum_stasis;
    new go_resonite_cask;
    new go_sacred_fire_of_life;
    new go_tele_to_dalaran_crystal;
    new go_tele_to_violet_stand;
    new go_fel_crystalforge;
    new go_bashir_crystalforge;
    new go_matrix_punchograph;
    new go_scourge_cage;
    new go_arcane_prison;
    new go_blood_filled_orb;
    new go_jotunheim_cage;
    new go_table_theka;
    new go_inconspicuous_landmark;
    new go_ethereal_teleport_pad;
    new go_soulwell;
    new go_tadpole_cage;
    new go_dragonflayer_cage;
    new go_amberpine_outhouse;
    new go_hive_pod;
    new go_massive_seaforium_charge;
    new go_gjalerbron_cage;
    new go_large_gjalerbron_cage;
    new go_veil_skith_cage;
    new go_frostblade_shrine;
    new go_midsummer_bonfire;
    new go_seaforium_charge;
    new go_mage_portal_pandaria;
    new go_challenge_orb();
    new go_dark_iron_mole_machine_wreckage();
	new go_goblinescapepod();
	new go_hyjal_flameward();
}
#endif
