////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////

#ifndef TRINITY_CONDITIONMGR_H
#define TRINITY_CONDITIONMGR_H

#include "Common.h"

class Creature;
class Player;
class Unit;
class WorldObject;
class LootTemplate;
struct Condition;

enum ConditionTypes
{                                                           // value1           value2         value3
    CONDITION_NONE                  = 0,                    // 0                0              0                  always true
    CONDITION_AURA                  = 1,                    // spell_id         effindex       use target?        true if player (or target, if value3) has aura of spell_id with effect effindex
    CONDITION_ITEM                  = 2,                    // item_id          count          bank               true if has #count of item_ids (if 'bank' is set it searches in bank slots too)
    CONDITION_ITEM_EQUIPPED         = 3,                    // item_id          0              0                  true if has item_id equipped
    CONDITION_ZONEID                = 4,                    // zone_id          0              0                  true if in zone_id
    CONDITION_REPUTATION_RANK       = 5,                    // faction_id       rankMask       0                  true if has min_rank for faction_id
    CONDITION_TEAM                  = 6,                    // player_team      0,             0                  469 - Alliance, 67 - Horde)
    CONDITION_SKILL                 = 7,                    // skill_id         skill_value    0                  true if has skill_value for skill_id
    CONDITION_QUESTREWARDED         = 8,                    // quest_id         0              0                  true if quest_id was rewarded before
    CONDITION_QUESTTAKEN            = 9,                    // quest_id         0,             0                  true while quest active
    CONDITION_DRUNKENSTATE          = 10,                   // DrunkenState     0,             0                  true if player is drunk enough
    CONDITION_WORLD_STATE           = 11,                   // index            value          0                  true if world has the value for the index
    CONDITION_ACTIVE_EVENT          = 12,                   // event_id         0              0                  true if event is active
    CONDITION_INSTANCE_DATA         = 13,                   // entry            data           0                  true if data is set in current instance
    CONDITION_QUEST_NONE            = 14,                   // quest_id         0              0                  true if doesn't have quest saved
    CONDITION_CLASS                 = 15,                   // class            0              0                  true if player's class is equal to class
    CONDITION_RACE                  = 16,                   // race             0              0                  true if player's race is equal to race
    CONDITION_ACHIEVEMENT           = 17,                   // achievement_id   0              0                  true if achievement is complete
    CONDITION_TITLE                 = 18,                   // title id         0              0                  true if player has title
    CONDITION_SPAWNMASK             = 19,                   // spawnMask        0              0
    CONDITION_GENDER                = 20,                   // gender           0              0                  true if player's gender is equal to gender
    CONDITION_UNUSED_21             = 21,                   //
    CONDITION_MAPID                 = 22,                   // map_id           0              0                  true if in map_id
    CONDITION_AREAID                = 23,                   // area_id          0              0                  true if in area_id
    CONDITION_UNUSED_24             = 24,                   //
    CONDITION_SPELL                 = 25,                   // spell_id         0              0                  true if player has learned spell
    CONDITION_PHASEID               = 26,                   // phaseid          0              0                  true if object is in phaseid
    CONDITION_LEVEL                 = 27,                   // level            ComparisonType 0                  true if unit's level is equal to param1 (param2 can modify the statement)
    CONDITION_QUEST_COMPLETE        = 28,                   // quest_id         0              0                  true if player has quest_id with all objectives complete, but not yet rewarded
    CONDITION_NEAR_CREATURE         = 29,                   // creature entry   distance       0                  true if there is a creature of entry in range
    CONDITION_NEAR_GAMEOBJECT       = 30,                   // gameobject entry distance       0                  true if there is a gameobject of entry in range
    CONDITION_OBJECT_ENTRY          = 31,                   // TypeID           entry          0                  true if object is type TypeID and the entry is 0 or matches entry of the object
    CONDITION_TYPE_MASK             = 32,                   // TypeMask         0              0                  true if object is type object's TypeMask matches provided TypeMask
    CONDITION_RELATION_TO           = 33,                   // ConditionTarget  RelationType   0                  true if object is in given relation with object specified by ConditionTarget
    CONDITION_REACTION_TO           = 34,                   // ConditionTarget  rankMask       0                  true if object's reaction matches rankMask object specified by ConditionTarget
    CONDITION_DISTANCE_TO           = 35,                   // ConditionTarget  distance       ComparisonType     true if object and ConditionTarget are within distance given by parameters
    CONDITION_ALIVE                 = 36,                   // 0                0              0                  true if unit is alive
    CONDITION_HP_VAL                = 37,                   // hpVal            ComparisonType 0                  true if unit's hp matches given value
    CONDITION_HP_PCT                = 38,                   // hpPct            ComparisonType 0                  true if unit's hp matches given pct
    CONDITION_HAS_BUILDING_TYPE     = 39,                   // BuildingType                                       true if player has this building activated in Garrison
    CONDITION_HAS_GARRISON_LEVEL    = 40,                   // Level
    CONDITION_MAX                                           // MAX
};

/*! Documentation on implementing a new ConditionSourceType:
    Step 1: Check for the lowest free ID. Look for CONDITION_SOURCE_TYPE_UNUSED_XX in the enum.
            Then define the new source type.

    Step 2: Determine and map the parameters for the new condition type.

    Step 3: Add a case block to ConditionMgr::isSourceTypeValid with the new condition type
            and validate the parameters.

    Step 4: If your condition can be grouped (determined in step 2), add a rule for it in
            ConditionMgr::CanHaveSourceGroupSet, following the example of the existing types.

    Step 5: Define the maximum available condition targets in ConditionMgr::GetMaxAvailableConditionTargets.

    The following steps only apply if your condition can be grouped:

    Step 6: Determine how you are going to store your conditions. You need to add a new storage container
            for it in ConditionMgr class, along with a function like:
            ConditionContainer GetConditionsForXXXYourNewSourceTypeXXX(parameters...)

            The above function should be placed in upper level (practical) code that actually
            checks the conditions.

    Step 7: Implement loading for your source type in ConditionMgr::LoadConditions.

    Step 8: Implement memory cleaning for your source type in ConditionMgr::Clean.
*/
enum ConditionSourceType
{
    CONDITION_SOURCE_TYPE_NONE                           = 0,
    CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE         = 1,
    CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE       = 2,
    CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE          = 3,
    CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE       = 4,
    CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE             = 5,
    CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE             = 6,
    CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE          = 7,
    CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE    = 8,
    CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE      = 9,
    CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE        = 10,
    CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE         = 11,
    CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE            = 12,
    CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET          = 13,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU                    = 14,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION             = 15,
    CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE      = 16,
    CONDITION_SOURCE_TYPE_SPELL                          = 17,
    CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT              = 18,
    CONDITION_SOURCE_TYPE_QUEST_ACCEPT                   = 19,
    CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK                = 20,
    CONDITION_SOURCE_TYPE_VEHICLE_SPELL                  = 21,
    CONDITION_SOURCE_TYPE_SMART_EVENT                    = 22,
    CONDITION_SOURCE_TYPE_NPC_VENDOR                     = 23,
    CONDITION_SOURCE_TYPE_PHASE_DEFINITION               = 24,
    CONDITION_SOURCE_TYPE_SPELL_PROC                     = 25,
    CONDITION_SOURCE_TYPE_MAX                            = 26  //MAX
};

enum ComparisionType
{
    COMP_TYPE_EQ = 0,
    COMP_TYPE_HIGH,
    COMP_TYPE_LOW,
    COMP_TYPE_HIGH_EQ,
    COMP_TYPE_LOW_EQ,
    COMP_TYPE_MAX
};

enum RelationType
{
    RELATION_SELF = 0,
    RELATION_IN_PARTY,
    RELATION_IN_RAID_OR_PARTY,
    RELATION_OWNED_BY,
    RELATION_PASSENGER_OF,
    RELATION_CREATED_BY,
    RELATION_MAX
};

enum
{
    MAX_CONDITION_TARGETS = 3
};

struct ConditionSourceInfo
{
    WorldObject* mConditionTargets[MAX_CONDITION_TARGETS]; // an array of targets available for conditions
    Condition const* mLastFailedCondition;
    ConditionSourceInfo(WorldObject* target0, WorldObject* target1 = NULL, WorldObject* target2 = NULL)
    {
        mConditionTargets[0] = target0;
        mConditionTargets[1] = target1;
        mConditionTargets[2] = target2;
        mLastFailedCondition = NULL;
    }
};

struct Condition
{
    ConditionSourceType     SourceType;        //SourceTypeOrReferenceId
    uint32                  SourceGroup;
    int32                   SourceEntry;
    uint32                  SourceId;          // So far, only used in CONDITION_SOURCE_TYPE_SMART_EVENT
    uint32                  ElseGroup;
    ConditionTypes          ConditionType;     //ConditionTypeOrReference
    uint32                  ConditionValue1;
    uint32                  ConditionValue2;
    uint32                  ConditionValue3;
    uint32                  ErrorTextId;
    uint32                  ReferenceId;
    uint32                  ScriptId;
    uint8                   ConditionTarget;
    bool                    NegativeCondition;

    Condition()
    {
        SourceType         = CONDITION_SOURCE_TYPE_NONE;
        SourceGroup        = 0;
        SourceEntry        = 0;
        ElseGroup          = 0;
        ConditionType      = CONDITION_NONE;
        ConditionTarget    = 0;
        ConditionValue1    = 0;
        ConditionValue2    = 0;
        ConditionValue3    = 0;
        ReferenceId        = 0;
        ErrorTextId        = 0;
        ScriptId           = 0;
        NegativeCondition  = false;
    }

    bool Meets(ConditionSourceInfo& sourceInfo) const;
    uint32 GetSearcherTypeMaskForCondition() const;
    bool isLoaded() const { return ConditionType > CONDITION_NONE || ReferenceId; }
    uint32 GetMaxAvailableConditionTargets() const;
};

typedef std::vector<Condition*> ConditionContainer;
typedef std::unordered_map<uint32 /*SourceEntry*/, ConditionContainer> ConditionsByEntryMap;
typedef std::array<ConditionsByEntryMap, CONDITION_SOURCE_TYPE_MAX> ConditionEntriesByTypeArray;
typedef std::unordered_map<uint32, ConditionsByEntryMap> ConditionEntriesByCreatureIdMap;
typedef std::unordered_map<std::pair<int32, uint32 /*SAI source_type*/>, ConditionsByEntryMap> SmartEventConditionContainer;
typedef std::unordered_map<int32 /*zoneId*/, ConditionsByEntryMap> PhaseDefinitionConditionContainer;

typedef std::unordered_map<uint32, ConditionContainer> ConditionReferenceContainer;//only used for references

class ConditionMgr
{
    friend class ACE_Singleton<ConditionMgr, ACE_Null_Mutex>;

    private:
        ConditionMgr();
        ~ConditionMgr();

    public:
        void LoadConditions(bool isReload = false);
        bool isConditionTypeValid(Condition* cond) const;

        uint32 GetSearcherTypeMaskForConditionList(ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(WorldObject* object, ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(WorldObject* object1, WorldObject* object2, ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const;
        bool CanHaveSourceGroupSet(ConditionSourceType sourceType) const;
        bool CanHaveSourceIdSet(ConditionSourceType sourceType) const;
        bool IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, ConditionSourceInfo& sourceInfo) const;
        bool IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, WorldObject* target0, WorldObject* target1 = nullptr, WorldObject* target2 = nullptr) const;
        bool HasConditionsForNotGroupedEntry(ConditionSourceType sourceType, uint32 entry) const;
        bool IsObjectMeetingSpellClickConditions(uint32 creatureId, uint32 spellId, WorldObject* clicker, WorldObject* target) const;
        ConditionContainer const* GetConditionsForSpellClickEvent(uint32 creatureId, uint32 spellId) const;
        bool IsObjectMeetingVehicleSpellConditions(uint32 creatureId, uint32 spellId, Player* player, Unit* vehicle) const;
        bool IsObjectMeetingSmartEventConditions(int32 entryOrGuid, uint32 eventId, uint32 sourceType, Unit* unit, WorldObject* baseObject) const;
        bool IsObjectMeetingVendorItemConditions(uint32 creatureId, uint32 itemId, Player* player, Creature* vendor) const;
        bool IsObjectMeetPhaseCondition(uint32 zone, uint32 entry, WorldObject* object) const;
        ConditionContainer const* GetConditionsForPhaseDefinition(uint32 zone, uint32 entry) const;

    private:
        bool isSourceTypeValid(Condition* cond) const;
        bool addToLootTemplate(Condition* cond, LootTemplate* loot) const;
        bool addToGossipMenus(Condition* cond) const;
        bool addToGossipMenuItems(Condition* cond) const;
        bool addToSpellImplicitTargetConditions(Condition* cond) const;
        bool IsObjectMeetToConditionList(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const;

        void Clean(); // free up resources
        std::vector<Condition*> AllocatedMemoryStore; // some garbage collection :)

        ConditionEntriesByTypeArray         ConditionStore;
        ConditionReferenceContainer         ConditionReferenceStore;
        ConditionEntriesByCreatureIdMap     VehicleSpellConditionStore;
        ConditionEntriesByCreatureIdMap     SpellClickEventConditionStore;
        ConditionEntriesByCreatureIdMap     NpcVendorConditionContainerStore;
        SmartEventConditionContainer        SmartEventConditionStore;
        PhaseDefinitionConditionContainer   PhaseDefinitionsConditionStore;
};

template <class T> bool CompareValues(ComparisionType type,  T val1, T val2)
{
    switch (type)
    {
        case COMP_TYPE_EQ:
            return val1 == val2;
        case COMP_TYPE_HIGH:
            return val1 > val2;
        case COMP_TYPE_LOW:
            return val1 < val2;
        case COMP_TYPE_HIGH_EQ:
            return val1 >= val2;
        case COMP_TYPE_LOW_EQ:
            return val1 <= val2;
        default:
            // incorrect parameter
            ASSERT(false);
            return false;
    }
}

#define sConditionMgr ACE_Singleton<ConditionMgr, ACE_Null_Mutex>::instance()

#endif
