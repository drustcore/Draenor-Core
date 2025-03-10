-- --------------------------------------------------------
-- Host:                         logon.hellscream.org
-- Server version:               5.5.9-log - MySQL Community Server (GPL)
-- Server OS:                    Win32
-- HeidiSQL Version:             10.3.0.5771
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Dumping structure for table worldpvp.spell_linked_spell
CREATE TABLE IF NOT EXISTS `spell_linked_spell` (
  `spell_trigger` mediumint(8) NOT NULL,
  `spell_effect` mediumint(8) NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  UNIQUE KEY `trigger_effect_type` (`spell_trigger`,`spell_effect`,`type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spell System';

-- Dumping data for table worldpvp.spell_linked_spell: 328 rows
DELETE FROM `spell_linked_spell`;
/*!40000 ALTER TABLE `spell_linked_spell` DISABLE KEYS */;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
	(61122, 55038, 0, 'Contact Brann'),
	(47585, 63230, 2, 'Dispersion (immunity)'),
	(17767, 54501, 2, 'Consume Shadows - Rank 1'),
	(-5143, -36032, 0, 'Arcane Missiles Rank 1'),
	(53563, 53651, 2, 'Beacon of Light'),
	(781, 56446, 0, 'Disengage'),
	(57635, 57636, 0, 'Disengage'),
	(60932, 60934, 0, 'Disengage'),
	(61507, 61508, 0, 'Disengage'),
	(34709, -1784, 1, 'Shadow Sight - Stealth'),
	(147647, 147648, 1, 'Grasp of Y\'Shaarj damage - Cast Grasp of Y\'Shaarj summon Manifestation on Spellhit.'),
	(52415, 52418, 0, 'Carrying Seaforium - Add'),
	(52610, 62071, 0, 'Savage Roar'),
	(-52610, -62071, 0, 'Savage Roar'),
	(20594, 65116, 0, 'Stoneform'),
	(49039, 50397, 2, 'Lichborne - shapeshift'),
	(64382, 64380, 0, 'Shattering Throw'),
	(-59907, 7, 0, 'Lightwell Charges - Suicide'),
	(40214, 40216, 2, 'Dragonmaw Illusion'),
	(40214, 42016, 2, 'Dragonmaw Illusion'),
	(36574, 36650, 0, 'Apply Phase Slip Vulnerability'),
	(-30410, 44032, 0, 'Manticron Cube Mind Exhaustion'),
	(-33711, 33686, 0, 'Murmur\'s Shockwave (Normal)'),
	(-38794, 33686, 0, 'Murmur\'s Shockwave (Heroic)'),
	(33686, 31705, 0, 'Murmur\'s Shockwave Jump'),
	(44008, 45265, 1, 'Static Disruption Visual'),
	(43648, 44007, 1, 'Storm Eye Safe Zone'),
	(44007, -43657, 2, 'Storm Eye Safe Zone Immune'),
	(43658, 43653, 0, 'Electrical Arc Visual'),
	(43658, 43654, 0, 'Electrical Arc Visual'),
	(43658, 43655, 0, 'Electrical Arc Visual'),
	(43658, 43656, 0, 'Electrical Arc Visual'),
	(43658, 43659, 0, 'Electrical Arc Visual'),
	(39835, 39968, 1, 'Needle Spine'),
	(-41376, 41377, 0, 'Spite'),
	(41126, 41131, 1, 'Flame Crash'),
	(-41914, 41915, 0, 'Summon Parasitic Shadowfiend'),
	(-41917, 41915, 0, 'Summon Parasitic Shadowfiend'),
	(39908, 40017, 1, 'Eye Blast'),
	(40604, 40616, 1, 'Fel Rage Aura'),
	(40616, 41625, 1, 'Fel Rage Aura'),
	(41292, 42017, 2, 'Aura of Suffering'),
	(44869, 44866, 1, 'Spectral Blast Portal'),
	(44869, 46019, 1, 'Spectral Blast Teleport'),
	(46019, 46021, 1, 'Spectral Realm Aura'),
	(-46021, 46020, 0, 'Teleport: Normal Realm'),
	(46020, 44867, 1, 'Spectral Exhaustion'),
	(44867, -46019, 2, 'Spectral Exhaustion - Teleport: Spectral Realm'),
	(45661, 45665, 1, 'Encapsulate'),
	(45347, -45348, 1, 'Remove Flame Touched'),
	(45348, -45347, 1, 'Remove Dark Touched'),
	(45248, 45347, 1, 'Apply Dark Touched'),
	(45329, 45347, 1, 'Apply Dark Touched'),
	(45256, 45347, 1, 'Apply Dark Touched'),
	(45270, 45347, 1, 'Apply Dark Touched'),
	(45342, 45348, 1, 'Apply Flame Touched'),
	(46771, 45348, 1, 'Apply Flame Touched'),
	(45271, 45347, 1, 'Apply Dark Touched'),
	(44869, -45018, 1, 'Remove Arcane Buffet'),
	(46019, -45018, 1, 'Remove Arcane Buffet'),
	(46242, 46247, 0, 'Black Hole Visual (Birth)'),
	(46228, 46235, 0, 'Black Hole Visual (Grown)'),
	(46228, -46247, 0, 'Black Hole Visual (Grown)'),
	(46262, 46265, 0, 'Void Zone Visual'),
	(-55053, 55601, 0, 'Deathbloom (H)'),
	(-29865, 55594, 0, 'Deathbloom'),
	(54097, -54100, 1, 'Widow\'s Embrace - Frenzy (H)'),
	(28732, -28798, 1, 'Widow\'s Embrace - Frenzy'),
	(58666, 58672, 1, 'Impale (Archavon)'),
	(60882, 58672, 1, 'Impale (Archavon)'),
	(-54361, 54343, 0, 'Void Shift (Normal) - Void Shifted'),
	(-59743, 54343, 0, 'Void Shift (Heroic) - Void Shifted'),
	(-28169, 28206, 0, 'Mutating Injection - Mutagen Explosion'),
	(-28169, 28240, 0, 'Mutating Injection - Poison Cloud'),
	(28059, -28084, 1, 'Positive Charge - Negative Charge'),
	(-28059, -29659, 0, 'Positive Charge'),
	(28084, -28059, 1, 'Negative Charge - Positive Charge'),
	(-28084, -29660, 0, 'Negative Charge'),
	(39088, -39091, 1, 'Positive Charge - Negative Charge'),
	(-39088, -29659, 0, 'Positive Charge'),
	(39091, -39088, 1, 'Negative Charge - Positive Charge'),
	(-39091, -39092, 0, 'Negative Charge'),
	(54581, 54623, 0, 'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object'),
	(45458, 45437, 1, 'Holiday - Midsummer, Stamp Out Bonfire, Quest Complete triggers Stamp Out Bonfire'),
	(54581, 57444, 0, 'Mammoth Explosion Spell Spawner link to Summon Main Mammoth Meat'),
	(54581, 54628, 0, 'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object'),
	(54581, 54627, 0, 'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object'),
	(-62475, -62399, 0, 'System Shutdown - Overload Circuit'),
	(-62475, -62375, 0, 'System Shutdown - Gathering Speed'),
	(-62475, 62472, 0, 'System Shutdown'),
	(62427, 62340, 2, 'Load into Catapult - Passenger Loaded'),
	(54643, -54643, 2, 'Wintergrasp Defender Teleport'),
	(54850, 54851, 1, 'Emerge - Emerge Summon'),
	(-30421, 38637, 0, 'Netherspite\'s Perseverence'),
	(-30422, 38638, 0, 'Netherspite\'s Serenity'),
	(-30423, 38639, 0, 'Netherspite\'s Dominance'),
	(66680, 66547, 0, 'Confess - Confess'),
	(66889, -66865, 0, 'Remove Vengeance'),
	(66744, 66747, 0, 'totem of the earthen ring'),
	(53099, 53098, 0, 'trigger teleport to acherus (for quest 12757)'),
	(45524, 55095, 0, 'Chains of Ice - Frost Fever'),
	(52410, -52418, 0, 'Carrying Seaforium - Remove'),
	(69378, 72586, 1, 'Drums of the Forgotten Kings'),
	(69377, 72590, 1, 'Runescroll of Fortitude'),
	(-48417, -47406, 0, 'On Strip Detect Drakuru 04 fade - Remove Envision Drakuru'),
	(54861, -23335, 0, 'Drop Flag on Nitro Boost WSG'),
	(54861, -23333, 0, 'Drop Flag on Nitro Boost WSG'),
	(55004, -23335, 0, 'Drop Flag on Nitro Boost WSG'),
	(55004, -23333, 0, 'Drop Flag on Nitro Boost WSG'),
	(54861, -34976, 0, 'Drop Flag on Nitro Boost EOS'),
	(55004, -34976, 0, 'Drop Flag on Nitro Boost EOS'),
	(50141, 50001, 0, 'Blood Oath to Blood Oath Aura'),
	(61263, 61267, 0, 'Intravenous Healing Effect'),
	(61263, 61268, 0, 'Intravenous Mana Regeneration Effect'),
	(66870, -66823, 1, 'Remove Paralytic Toxin when hit by Burning Bite'),
	(-66683, 68667, 0, 'Icehowl - Surge of Adrenaline'),
	(58875, 58876, 1, 'Spirit Walk'),
	(7744, 72757, 0, 'Will of the Forsaken Cooldown Trigger (WOTF)'),
	(42292, 72752, 0, 'Will of the Forsaken Cooldown Trigger'),
	(59752, 72752, 0, 'Will of the Forsaken Cooldown Trigger'),
	(-68839, 68846, 0, 'Bronjahm: Corrupt Soul Summon'),
	(-70980, 71010, 0, 'Web Wrap'),
	(24714, 24750, 1, 'Trick cast Trick'),
	(41621, 52656, 2, 'Stun if Wolpertinger net aura'),
	(41621, 63726, 2, 'Pacify if Wolpertinger net aura'),
	(-43883, -42146, 0, 'Remove Brewfest Ram DND when Rental racing ram removed'),
	(-43883, -43310, 0, 'Remove Ram level Neutral when Rental racing ram removed'),
	(-43883, -42992, 0, 'Rental racing ram removed removes Trot'),
	(-43883, -42993, 0, 'Rental racing ram removed removes Canter'),
	(-43883, -42994, 0, 'Rental racing ram removed removes Gallop'),
	(-43883, -43332, 0, 'Rental racing ram removed removes Exhausted'),
	(42992, -42993, 0, 'Trot removes Canter'),
	(42992, -42994, 0, 'Trot removes Gallop'),
	(42993, -42992, 0, 'Canter removes Trot'),
	(42993, -42994, 0, 'Canter removes Gallop'),
	(42994, -42992, 0, 'Gallop removes Trot'),
	(42994, -42993, 0, 'Gallop removes Canter'),
	(43332, -42992, 0, 'Exhausted removes Trot'),
	(43332, -42993, 0, 'Exhausted removes Canter'),
	(43332, -42994, 0, 'Exhausted removes Gallop'),
	(57787, -57745, 1, 'Remove See Quest Invisibility 1 When hit by quest chain end spell'),
	(50517, -51926, 0, 'Corsair Costume - Remover'),
	(56684, -56687, 0, 'remove passenger on spell cast'),
	(56683, -56726, 1, 'remove web on rescue spell hit'),
	(58984, 59646, 0, 'Shadowmeld: Sanctuary'),
	(58984, 62196, 0, 'Shadowmeld: Force deselect'),
	(70867, 70871, 2, 'Blood-Queen: Essence of the Blood Queen'),
	(70879, 70871, 2, 'Blood-Queen: Essence of the Blood Queen'),
	(70877, 72649, 2, 'Blood-Queen: Frenzied Bloodthirst 10man'),
	(70877, 72151, 2, 'Blood-Queen: Frenzied Bloodthirst 10man'),
	(70923, 70924, 1, 'Blood-Queen: Uncontrollable Frenzy damage buff'),
	(71446, 71447, 1, 'Blood-Queen: Bloodbolt Splash'),
	(71952, 70995, 1, 'Blood-Queen: Presence of the Darkfallen'),
	(26286, 44430, 0, 'Small Red Rocket - questcredit'),
	(50317, 50487, 0, 'Disco Ball'),
	(50317, 50314, 0, 'Disco Ball'),
	(66548, 66550, 0, 'Isle of Conquest (IN>OUT)'),
	(66549, 66551, 0, 'Isle of Conquest (OUT>IN)'),
	(66551, -66548, 2, 'Isle of Conquest Teleport (OUT>IN) Debuff limit'),
	(66550, -66549, 2, 'Isle of Conquest Teleport (IN>OUT) Debuff limit'),
	(26292, 44430, 0, 'Small Green Rocket - questcredit'),
	(26291, 44430, 0, 'Small Blue Rocket - questcredit'),
	(26327, 44429, 0, 'Red Firework Cluster - questcredit'),
	(26325, 44429, 0, 'Green Firework Cluster - questcredit'),
	(26304, 44429, 0, 'Blue Firework Cluster - questcredit'),
	(65940, 65941, 0, 'Trial of the Crusader: Shattering Throw'),
	(70157, 69700, 2, 'Sindragosa - Ice Tomb resistance'),
	(55814, 55817, 1, 'Eck Residue'),
	(147640, 147644, 1, 'Charge - Cast Reaper on Spellhit.'),
	(-32756, -38080, 0, 'Shadowy Disguise: Remove model aura'),
	(-32756, -38081, 0, 'Shadowy Disguise: Remove model aura'),
	(-57350, 60242, 0, 'Darkmoon Card: Illusion'),
	(-70447, 70530, 0, 'Putricide: Volatile Ooze Adhesive Protection'),
	(61734, 61719, 2, 'Noblegarden Bunny: Lay Egg periodic'),
	(61716, 61719, 2, 'Rabbit Costume: Lay Egg periodic'),
	(-47960, -63311, 0, 'Glyph of Shadowflame Rank 1'),
	(-48265, -50392, 0, 'Improved Unholy Presence'),
	(48810, 48809, 0, 'Cast Binding Life when cast Death\'s Door'),
	(-48809, -48143, 0, 'Removing Binding Life removes Forgotten Aura'),
	(48143, 48357, 0, 'Aura Wintergarde Invisibility Type B when aura Forgotten Aura'),
	(-48143, -48357, 0, 'Removing Binding Forgotten Aura removes Aura Wintergarde Invisibility Type B'),
	(61990, -62457, 2, 'Hodir - Ice Shards Immunity'),
	(61990, -65370, 2, 'Hodir - Ice Shards Immunity'),
	(62821, -62469, 2, 'Toasty fire - Freeze imunity'),
	(62821, -62039, 2, 'Toasty fire - Biting cold imunity'),
	(61969, 7940, 2, 'Hodir - Flash Freeze immunity'),
	(61990, 7940, 2, 'Hodir - Flash Freeze immunity'),
	(-70923, -70924, 0, 'Blood-Queen: Uncontrollable Frenzy remove 10man'),
	(24071, 24020, 1, 'Axe Flurry will now throw axes at nearby players, stunning them'),
	(24023, 12021, 1, 'Charge (24023) will now trigger Fixate'),
	(55288, 55289, 0, 'Ocular on script cast killcredit'),
	(-47403, -47317, 0, 'On Strip Detect Drakuru 03 fade - Remove Envision Drakuru'),
	(-47308, -47150, 0, 'On Strip Detect Drakuru 02 fade - Remove Envision Drakuru'),
	(-47122, -47118, 0, 'On Strip Detect Drakuru fade - Remove Envision Drakuru'),
	(45980, 46022, 0, 'Re-Cursive quest'),
	(65686, -65684, 2, 'Remove Dark Essence 10M'),
	(65684, -65686, 2, 'Remove Light Essence 10M'),
	(66512, 66510, 0, 'Summon Deep Jormungar on Pound Drum'),
	(46770, 47972, 1, 'Liquid Fire of Elune'),
	(47311, 47925, 0, 'Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object'),
	(47311, 47924, 0, 'Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object'),
	(47311, 47309, 0, 'Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object'),
	(-68054, 68052, 0, 'Jeeves - Say Goodbye'),
	(-52098, 52092, 0, 'Charge Up - Temporary Electrical Charge'),
	(57908, 57915, 0, 'q13129 - Give quest item'),
	(53288, 53289, 1, 'Flight - Onequah to Light\'s Breach trigger Flight - Onequah to Light\'s Breach'),
	(53311, 53310, 1, 'Flight - Westfall to Light\'s Breach trigger Flight - Westfall to Light\'s Breach'),
	(61613, -61611, 1, 'Ganjo\'s Resurrection removes On The Other Side'),
	(-43351, 50167, 0, ''),
	(-43351, 61720, 0, ''),
	(54640, 54643, 0, 'WG teleporter'),
	(125122, 125253, 0, 'Quest 31302: Rice Pudding Kill Credit'),
	(125117, 125192, 0, 'Quest 31281: Sliced Peaches Kill Credit'),
	(19263, -23333, 0, 'Deterrence removes Horde Flag'),
	(66010, 25771, 0, 'Divine Shield - Forbearance'),
	(50440, 50446, 1, 'On Envision Drakuru - Spellcast Summon Drakuru'),
	(57889, 57891, 0, 'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of Vardmadra'),
	(57889, 57885, 0, 'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of a Shadow Cultist'),
	(48750, 48770, 2, 'Serinar\'s Vision is applied while aura Burning Depths Necrolyte Image is active'),
	(-41909, 45254, 0, 'On spellfade Hex of Air Knockback - Spellcast Suicide'),
	(52279, 45254, 1, 'On spellhit Tua-Tua on Burn - Spellcast Suicide'),
	(52287, 4309, 2, 'On aura Hex of Frost - Apply High Priest Immunity'),
	(52303, 45254, 1, 'On spellhit Hawinni on Frozen - Spellcast Suicide'),
	(-48266, -50385, 0, 'Improved Frost Presence'),
	(5487, 17057, 0, 'Switching in bear form gain 10 rage'),
	(-120086, -123154, 0, 'Fists of Fury Target Visual Removal on Stun Removal'),
	(-23333, -46392, 0, 'Focused Assault Removal on Horde Flag Drop/Capture/Removal'),
	(-23335, -46392, 0, 'Focused Assault Removal on Alliance Flag Drop/Capture/Removal'),
	(-23333, -46393, 0, 'Brutal Assault Removal on Horde Flag Drop/Capture/Removal'),
	(-23335, -46393, 0, 'Brutal Assault Removal on Alliance Flag Drop/Capture/Removal'),
	(120451, -108503, 0, 'Remove GoS from Warlock upon casting Flames of Xoroth'),
	(712, -108503, 0, 'Remove GoS from Warlock upon summoning Succubus'),
	(12880, 115993, 0, 'Burning Anger - Enrage Add'),
	(12880, 89031, 0, 'Glyph of Enraged Speed - Mod +20% speed add'),
	(-12880, -89031, 0, 'Glyph of Enraged Speed - Mod +20% speed remove'),
	(134359, -156618, 0, 'Golem Aereo Horde Cart'),
	(134359, -156621, 0, 'Golem Aereo removes Ally Cart'),
	(45834, 45837, 0, ''),
	(45835, 45837, 0, ''),
	(86507, 96175, 1, 'Runescroll of Fortitude II'),
	(61611, 61612, 1, 'Summon body when going to other side'),
	(-47744, 61611, 0, 'Cast other side when curse expires'),
	(-48263, -50371, 0, 'Improved Blood Presence'),
	(42965, 42919, 0, 'Hallows End - Tricky Treat'),
	(42966, -42965, 0, 'Hallows End - Upset Tummy removes Tricky Treat'),
	(42966, -42919, 0, 'Hallows End - Upset Tummy removes Tricky Treat'),
	(31224, 81549, 2, 'Rogue - Cloak of Shadows'),
	(2812, -115654, 0, 'Glyph of Denounce'),
	(19750, -114250, 0, 'Selfless Healer'),
	(102280, 768, 0, 'Displacer Beast'),
	(101603, -107837, 0, 'Echo of Baine - Throw Totem'),
	(101603, -101601, 0, 'Echo of Baine - Throw Totem'),
	(82665, 82666, 2, 'Feludius - Heart of Ice + Frost Imbued'),
	(82660, 82663, 2, 'Ignacious - Burning Blood + Flame Imbued'),
	(19263, -23335, 0, 'Deterrence removes Ally Flag'),
	(-65686, -65811, 0, 'Light Essence 10M'),
	(19263, -34976, 0, 'Deterrence removes EoSFlag'),
	(-65684, -65827, 0, 'Dark Essence 10M'),
	(105367, 105371, 1, 'Hagara the Stormbinder - Lightning Conduit'),
	(29531, 45390, 0, 'Ribbon Pole - Dancer Check Aura'),
	(45390, 45406, 2, 'Ribbon Pole - Periodic Visual'),
	(45723, 43313, 2, 'Torch Tossing - Target Indicator Visual'),
	(46747, 45907, 0, 'Fling Torch - Torch Target Picker'),
	(45792, 46120, 0, 'Torch Toss (Shadow), Slow'),
	(45806, 46118, 0, 'Torch Toss (Shadow), Medium'),
	(45816, 46117, 0, 'Torch Toss (Shadow), Fast'),
	(-93561, -94965, 2, 'Akma\'hat - Stone Mantle'),
	(103534, -103536, 1, 'Morchok - Danger'),
	(103534, -103541, 1, 'Morchok - Danger'),
	(103536, -103534, 1, 'Morchok - Warning'),
	(103536, -103541, 1, 'Morchok - Warning'),
	(103541, -103534, 1, 'Morchok - Safe'),
	(103541, -103536, 1, 'Morchok - Safe'),
	(69127, -28282, 1, 'EXPLOIT!!! Possible Lich King farm with Corrupted Ashbringer'),
	(71193, -71188, 0, 'Gunship Battle - Veteran removes Experimented'),
	(71195, -71193, 0, 'Gunship Battle - Elite removes Veteran'),
	(73077, 69188, 2, 'Gunship Battle - Fix visual for Rocket Pack'),
	(68645, 69193, 0, 'Gunship Battle - Fix visual for Rocket Pack'),
	(69193, 69192, 0, 'Gunship Battle - Cast Rocket Burst when landing with Rocket Pack'),
	(62042, 62470, 1, 'Stormhammer => Deafening Thunder'),
	(63277, 65269, 2, 'Shadow Crash auras'),
	(74555, 11196, 1, 'dense embersilk bandage'),
	(83958, 88306, 0, 'Summon Guild Chest'),
	(21014, 110440, 0, 'spell add item'),
	(58622, 58633, 0, 'Teleport to Lake Wintergrasp'),
	(121885, 129078, 1, 'Summon Amber Prison when hit by aura'),
	(73680, 73683, 0, 'Unleashs Elements'),
	(-181884, -181773, 0, 'S.E.L.F.I.E Filter'),
	(-181884, -181779, 0, 'S.E.L.F.I.E Filter'),
	(-181884, -181767, 0, 'S.E.L.F.I.E Filter'),
	(73680, 73681, 0, 'Unleashs Elements'),
	(152175, 158221, 0, 'Hurricane Strike cast Hurricane Strike (Damage)'),
	(-114050, -166100, 0, 'Ascendance Sham WoD PvP 2 removal'),
	(17007, 24932, 0, 'Leader of the Pack cast Leader of the pack (Mod crit %)'),
	(-171744, -93430, 0, 'Remove eclipse visual with eclipse buff'),
	(-171743, -93431, 0, 'Remove eclipse visual with eclipse buff'),
	(164546, 151626, 0, ''),
	(115070, 119651, 2, 'Mana Usage'),
	(137619, 140149, 2, 'Marked for Death (check caster)'),
	(182575, 182576, 0, 'SELFIE camera'),
	(182562, 181884, 0, 'S.E.L.F.I.E Camera MK II'),
	(106877, 106871, 1, 'Sha Spike Dummy Effect - Cast Sha Spike on Spellhit.'),
	(67526, -67502, 0, 'When Amazing G-ray cast, remove timer'),
	(67508, -67502, 0, 'When Blastcrackers cast, remove timer'),
	(67524, -67502, 0, 'When Ear-O-Scope cast, remove timer'),
	(67525, -67502, 0, 'When Infinifold Lockpick cast, remove timer'),
	(67522, -67502, 0, 'When Kajamite Drill cast remove timer'),
	(66911, 66930, 0, 'When Dance is cast, spawn disco ball'),
	(66910, 66931, 0, 'When Bucket is cast, spawn Bucket'),
	(66909, 75122, 0, 'When Bubbly is cast, Cast Bubbly'),
	(66912, 66917, 0, 'When Fireworks is cast, spawn Blue FIreworks'),
	(66913, 75124, 0, 'When Food is cast, spawn Food'),
	(355, 71, 0, 'Taunt trigger Defensive Stance'),
	(70192, -71507, 1, 'Remove Heavily Perfumed on Fragrant Air Analysis hit'),
	(71522, -71450, 1, 'Remove Crown Parcel Service Uniform on Crown Chemical Co. Supplies hit'),
	(71539, -71450, 1, 'Remove Crown Parcel Service Uniform on Crown Chemical Co. Supplies hit'),
	(-71450, -71459, 0, 'Remove Crown Chemical Co. Contraband when Crown Parcel Service Uniform is removed'),
	(34709, -115191, 1, 'Shadow Sight - Subterfuge'),
	(34709, -5215, 1, 'Shadow Sight - Prowl'),
	(6552, 67235, 1, 'Stitch : guerrier - Volée de coups : interompre '),
	(6552, 85387, 0, 'Stitch : guerrier - Volée de coups : stun '),
	(82742, 30010, 0, 'Stitch : MOB - Empaler et tirer '),
	(77416, 77417, 0, 'Stitch : La mine doit fermer ses volets 25811'),
	(80704, 80702, 0, 'Orbe de contrôle d\'ettin pour quete Il faut sauver le contremaître Oslow 26520'),
	(68167, 68086, 1, 'Stitch :  Quete Gloups ! Je suis un naga ! 14260 : morph'),
	(89821, 89824, 0, 'Stitch : Bâtonnet d\'Helcular, donne-moi ta force 28331-Bâtonnet d\'Helcular'),
	(71, 23691, 0, 'Stitch :  Guerrier - +20 rage avec Posture défensive'),
	(-38708, 38991, 0, 'Upon Demoniac Visitation expiring cast Summon Demonaic Visitation');
/*!40000 ALTER TABLE `spell_linked_spell` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
