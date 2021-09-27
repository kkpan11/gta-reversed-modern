/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "StdInc.h"

bool (&abTempNeverLeavesGroup)[7] = *(bool (*)[7])0xC0BC08;
int32& gPlayIdlesAnimBlockIndex = *(int32*)0xC0BC10;
bool& CPlayerPed::bHasDisplayedPlayerQuitEnterCarHelpText = *(bool*)0xC0BC15;

void CPlayerPed::InjectHooks() {
    using namespace ReversibleHooks;
    Install("CPlayerPed", "ResetSprintEnergy", 0x60A530, &CPlayerPed::ResetSprintEnergy);
    Install("CPlayerPed", "ResetPlayerBreath", 0x60A8A0, &CPlayerPed::ResetPlayerBreath);
    Install("CPlayerPed", "RemovePlayerPed", 0x6094A0, &CPlayerPed::RemovePlayerPed);
    Install("CPlayerPed", "Busted", 0x609EF0, &CPlayerPed::Busted);
    Install("CPlayerPed", "GetWantedLevel", 0x41BE60, &CPlayerPed::GetWantedLevel);
    Install("CPlayerPed", "SetWantedLevel", 0x609F10, &CPlayerPed::SetWantedLevel);
    Install("CPlayerPed", "SetWantedLevelNoDrop", 0x609F30, &CPlayerPed::SetWantedLevelNoDrop);
    Install("CPlayerPed", "CheatWantedLevel", 0x609F50, &CPlayerPed::CheatWantedLevel);
    Install("CPlayerPed", "DoStuffToGoOnFire", 0x60A020, &CPlayerPed::DoStuffToGoOnFire);
    Install("CPlayerPed", "Load", 0x5D46E0, &CPlayerPed::Load_Reversed);
    Install("CPlayerPed", "Save", 0x5D57E0, &CPlayerPed::Save_Reversed);
    Install("CPlayerPed", "DeactivatePlayerPed", 0x609520, &CPlayerPed::DeactivatePlayerPed);
    Install("CPlayerPed", "ReactivatePlayerPed", 0x609540, &CPlayerPed::ReactivatePlayerPed);
    Install("CPlayerPed", "GetPadFromPlayer", 0x609560, &CPlayerPed::GetPadFromPlayer);
    Install("CPlayerPed", "CanPlayerStartMission", 0x609590, &CPlayerPed::CanPlayerStartMission);
    Install("CPlayerPed", "IsHidden", 0x609620, &CPlayerPed::IsHidden);
    Install("CPlayerPed", "ReApplyMoveAnims", 0x609650, &CPlayerPed::ReApplyMoveAnims);
    Install("CPlayerPed", "DoesPlayerWantNewWeapon", 0x609710, &CPlayerPed::DoesPlayerWantNewWeapon);
    Install("CPlayerPed", "ProcessPlayerWeapon", 0x6097F0, &CPlayerPed::ProcessPlayerWeapon);
    Install("CPlayerPed", "PickWeaponAllowedFor2Player", 0x609800, &CPlayerPed::PickWeaponAllowedFor2Player);
    Install("CPlayerPed", "UpdateCameraWeaponModes", 0x609830, &CPlayerPed::UpdateCameraWeaponModes);
    Install("CPlayerPed", "ClearWeaponTarget", 0x609c80, &CPlayerPed::ClearWeaponTarget);
    Install("CPlayerPed", "GetWeaponRadiusOnScreen", 0x609CD0, &CPlayerPed::GetWeaponRadiusOnScreen);
    Install("CPlayerPed", "PedCanBeTargettedVehicleWise", 0x609D90, &CPlayerPed::PedCanBeTargettedVehicleWise);
    Install("CPlayerPed", "FindTargetPriority", 0x609DE0, &CPlayerPed::FindTargetPriority);
    Install("CPlayerPed", "Clear3rdPersonMouseTarget", 0x609ED0, &CPlayerPed::Clear3rdPersonMouseTarget);
    Install("CPlayerPed", "CanIKReachThisTarget", 0x609F80, &CPlayerPed::CanIKReachThisTarget);
    Install("CPlayerPed", "GetPlayerInfoForThisPlayerPed", 0x609FF0, &CPlayerPed::GetPlayerInfoForThisPlayerPed);
    Install("CPlayerPed", "AnnoyPlayerPed", 0x60A040, &CPlayerPed::AnnoyPlayerPed);
    Install("CPlayerPed", "ClearAdrenaline", 0x60A070, &CPlayerPed::ClearAdrenaline);
    Install("CPlayerPed", "DisbandPlayerGroup", 0x60A0A0, &CPlayerPed::DisbandPlayerGroup);
    Install("CPlayerPed", "MakeGroupRespondToPlayerTakingDamage", 0x60A110, &CPlayerPed::MakeGroupRespondToPlayerTakingDamage);
    Install("CPlayerPed", "TellGroupToStartFollowingPlayer", 0x60A1D0, &CPlayerPed::TellGroupToStartFollowingPlayer);
    Install("CPlayerPed", "MakePlayerGroupDisappear", 0x60A440, &CPlayerPed::MakePlayerGroupDisappear);
    Install("CPlayerPed", "MakePlayerGroupReappear", 0x60A4B0, &CPlayerPed::MakePlayerGroupReappear);
    Install("CPlayerPed", "HandleSprintEnergy", 0x60A550, &CPlayerPed::HandleSprintEnergy);
    // Install("CPlayerPed", "GetButtonSprintResults", 0x60A820, &CPlayerPed::GetButtonSprintResults);
    Install("CPlayerPed", "HandlePlayerBreath", 0x60A8D0, &CPlayerPed::HandlePlayerBreath);
    Install("CPlayerPed", "MakeChangesForNewWeapon", 0x60B460, static_cast<void(CPlayerPed::*)(eWeaponType)>(&CPlayerPed::MakeChangesForNewWeapon));
    Install("CPlayerPed", "LOSBlockedBetweenPeds", 0x60B550, &LOSBlockedBetweenPeds);
    Install("CPlayerPed", "DoesTargetHaveToBeBroken", 0x60C0C0, &CPlayerPed::DoesTargetHaveToBeBroken);
    Install("CPlayerPed", "SetPlayerMoveBlendRatio", 0x60C520, &CPlayerPed::SetPlayerMoveBlendRatio);
    Install("CPlayerPed", "FindPedToAttack", 0x60C5F0, &CPlayerPed::FindPedToAttack);
    Install("CPlayerPed", "ForceGroupToAlwaysFollow", 0x60C7C0, &CPlayerPed::ForceGroupToAlwaysFollow);
    Install("CPlayerPed", "ForceGroupToNeverFollow", 0x60C800, &CPlayerPed::ForceGroupToNeverFollow);
    Install("CPlayerPed", "MakeChangesForNewWeapon_BySlot", 0x60D000, static_cast<void(CPlayerPed::*)(uint32)>(&CPlayerPed::MakeChangesForNewWeapon));
    Install("CPlayerPed", "EvaluateTarget", 0x60D020, &CPlayerPed::EvaluateTarget);
    Install("CPlayerPed", "PlayerHasJustAttackedSomeone", 0x60D5A0, &CPlayerPed::PlayerHasJustAttackedSomeone);
    Install("CPlayerPed", "SetupPlayerPed", 0x60D790, &CPlayerPed::SetupPlayerPed);

}

struct WorkBufferSaveData {
    uint32          saveSize = sizeof(WorkBufferSaveData); // Never read, but written
    uint32          chaosLevel{};
    uint32          wantedLevel{};
    CPedClothesDesc clothesDesc{};
    uint32          chosenWeapon{};
};
VALIDATE_SIZE(WorkBufferSaveData, 132u + 4u);

// calls of LoadDataFromWorkBuffer are optimized
// 0x5D46E0
bool CPlayerPed::Load_Reversed() {
    CPed::Load();

    WorkBufferSaveData savedData{};
    CGenericGameStorage::LoadDataFromWorkBuffer(&savedData, sizeof(WorkBufferSaveData));

    CWanted* wanted = m_pPlayerData->m_pWanted;
    wanted->m_nChaosLevel = savedData.chaosLevel;
    wanted->m_nWantedLevel= savedData.wantedLevel;

    m_pPlayerData->m_nChosenWeapon = savedData.chosenWeapon;
    *m_pPlayerData->m_pPedClothesDesc = savedData.clothesDesc;

    return true;
}

// calls of SaveDataToWorkBuffer are optimized
// 0x5D57E0
bool CPlayerPed::Save_Reversed() {
    WorkBufferSaveData saveData{};

    CWanted* wanted = m_pPlayerData->m_pWanted;
    saveData.chaosLevel = wanted->m_nChaosLevel;
    saveData.wantedLevel = wanted->m_nWantedLevel;

    saveData.chosenWeapon = m_pPlayerData->m_nChosenWeapon;
    saveData.clothesDesc = *m_pPlayerData->m_pPedClothesDesc;

    CGenericGameStorage::SaveDataToWorkBuffer(&saveData, sizeof(WorkBufferSaveData));

    return true;
}

// 0x60D5B0
CPlayerPed::CPlayerPed(int32 playerId, bool bGroupCreated) : CPed(plugin::dummy) {
    plugin::CallMethod<0x60D5B0, CPlayerPed *, int32, bool>(this, playerId, bGroupCreated);
}

// 0x6094A0
void CPlayerPed::RemovePlayerPed(int32 playerId) {
    CPed* player = FindPlayerPed(playerId);
    CPlayerInfo* playerInfo = &FindPlayerInfo(playerId);
    if (player)
    {
        CVehicle* playerVehicle = player->m_pVehicle;
        if (playerVehicle && playerVehicle->m_pDriver == player)
        {
            playerVehicle->m_nStatus = STATUS_PHYSICS;
            playerVehicle->m_fGasPedal = 0.0f;
            playerVehicle->m_fBreakPedal = 0.1f;
        }
        CWorld::Remove(static_cast<CEntity*>(player));
        delete player;
        playerInfo->m_pPed = nullptr;
    }
}

// 0x609520
void CPlayerPed::DeactivatePlayerPed(int32 playerId) {
    assert(playerId >= 0);
    CWorld::Remove(FindPlayerPed(playerId));
}

// 0x609540
void CPlayerPed::ReactivatePlayerPed(int32 playerId) {
    assert(playerId >= 0);
    CWorld::Add(FindPlayerPed(playerId));
}

// 0x609560
CPad* CPlayerPed::GetPadFromPlayer() {
    switch (m_nPedType) {
    case ePedType::PED_TYPE_PLAYER1:
        return CPad::GetPad(0);

    case ePedType::PED_TYPE_PLAYER2:
        return CPad::GetPad(1);
    }
    assert(0); // shouldn't happen
    return nullptr;
}

// 0x609590
bool CPlayerPed::CanPlayerStartMission() {
    if (CGameLogic::GameState != GAME_STATE_INITIAL)
        return false;

    if (CGameLogic::IsCoopGameGoingOn())
        return false;

    if (!IsPedInControl() && !IsStateDriving())
        return false;

    if (GetTaskManager().GetTaskSecondary(eSecondaryTasks::TASK_SECONDARY_ATTACK))
        return false;

    if (GetTaskManager().GetTaskSecondary(eSecondaryTasks::TASK_SECONDARY_SAY))
        return false;

    if (auto task = GetTaskManager().GetTaskSecondary(eSecondaryTasks::TASK_SECONDARY_FACIAL_COMPLEX)) {
        if (task->GetTaskType() == eTaskType::TASK_SIMPLE_CAR_DRIVE) {
            return false;
        }
    }

    if (!IsAlive())
        return false;

    return !GetEventGroup().GetEventOfType(eEventType::EVENT_SCRIPT_COMMAND);
   
}

// 0x609620
bool CPlayerPed::IsHidden() {
    return bInVehicle && GetLightingTotal() <= 0.05f;
}

// 0x609650
void CPlayerPed::ReApplyMoveAnims() {
    constexpr AnimationId anims[]{
        AnimationId::ANIM_ID_WALK,
        AnimationId::ANIM_ID_RUN,
        AnimationId::ANIM_ID_SPRINT,
        AnimationId::ANIM_ID_IDLE,
        AnimationId::ANIM_ID_WALK_START
    };
    for (const AnimationId& id : anims) {
        if (CAnimBlendAssociation* anim = RpAnimBlendClumpGetAssociation(m_pRwClump, id)) {
            if (anim->GetHashKey() != CAnimManager::GetAnimAssociation(m_nAnimGroup, id)->GetHashKey()) {
                CAnimBlendAssociation* addedAnim = CAnimManager::AddAnimation(m_pRwClump, m_nAnimGroup, id);
                addedAnim->m_fBlendDelta = anim->m_fBlendDelta;
                addedAnim->m_fBlendAmount = anim->m_fBlendAmount;

                anim->m_nFlags |= ANIM_FLAG_FREEZE_LAST_FRAME;
                anim->m_fBlendDelta = -1000.0f;
            }
        }
    }
}

// 0x609710
bool CPlayerPed::DoesPlayerWantNewWeapon(eWeaponType weaponType, bool arg1) {
    // GetPadFromPlayer(); // Called, but not used

    auto weaponSlot = GetWeaponSlot(weaponType);
    auto weaponInSlotType = GetWeaponInSlot(weaponSlot).m_nType;
    if (weaponInSlotType == weaponType)
        return true;

    if (weaponInSlotType == eWeaponType::WEAPON_UNARMED)
        return true;

    if (arg1)
        return false;

    if (m_pIntelligence->GetTaskJetPack())
        return false;

    /* !See comment!
    if (m_nActiveWeaponSlot == weaponSlot
        && CWeaponInfo::GetWeaponInfo(weaponInSlotType, GetWeaponSkill(weaponInSlotType))->flags.bAimWithArm   \ One of these two is always false, so
        && !CWeaponInfo::GetWeaponInfo(weaponInSlotType, GetWeaponSkill(weaponInSlotType))->flags.bAimWithArm) / the whole expression is always false
        return false;
    */

    if (m_nActiveWeaponSlot == weaponSlot) {
        switch (m_nPedState) {
        case ePedState::PEDSTATE_ATTACK:
        case ePedState::PEDSTATE_AIMGUN:
            return false;
        }
    }

    return true;
}

// 0x6097F0
void CPlayerPed::ProcessPlayerWeapon(CPad* pad) {
    /* empty */
}

// 0x609800
void CPlayerPed::PickWeaponAllowedFor2Player() {
    if (!GetWeaponInSlot(m_pPlayerData->m_nChosenWeapon).CanBeUsedFor2Player())
        m_pPlayerData->m_nChosenWeapon = eWeaponType::WEAPON_UNARMED;
}

// 0x609830
void CPlayerPed::UpdateCameraWeaponModes(CPad* pad) {
    switch (GetActiveWeapon().m_nType) {
    case eWeaponType::WEAPON_M4:
        TheCamera.SetNewPlayerWeaponMode(eCamMode::MODE_M16_1STPERSON, 0, 0);
        break;

    case eWeaponType::WEAPON_SNIPERRIFLE:
        TheCamera.SetNewPlayerWeaponMode(eCamMode::MODE_SNIPER, 0, 0);
        break;

    case eWeaponType::WEAPON_RLAUNCHER:
        TheCamera.SetNewPlayerWeaponMode(eCamMode::MODE_ROCKETLAUNCHER, 0, 0);
        break;

    case eWeaponType::WEAPON_RLAUNCHER_HS:
        TheCamera.SetNewPlayerWeaponMode(eCamMode::MODE_ROCKETLAUNCHER_HS, 0, 0);
        break;

    case eWeaponType::WEAPON_CAMERA:
        TheCamera.SetNewPlayerWeaponMode(eCamMode::MODE_CAMERA, 0, 0);
        break;

    default:
        TheCamera.ClearPlayerWeaponMode();
        break;
    }
}

// 0x6098F0
void CPlayerPed::ProcessAnimGroups() {
    plugin::CallMethod<0x6098F0, CPlayerPed *>(this);
}

// 0x609C80
void CPlayerPed::ClearWeaponTarget() {
    if (IsPlayer()) {
        if (m_pTargetedObject)
            m_pTargetedObject->CleanUpOldReference(&m_pTargetedObject);
        m_pTargetedObject = nullptr;
        TheCamera.ClearPlayerWeaponMode();
        CWeaponEffects::ClearCrossHair(m_nPedType);
    }
}

// 0x609CD0
float CPlayerPed::GetWeaponRadiusOnScreen() {
    CWeapon& wep = GetActiveWeapon();
    CWeaponInfo& wepInfo = wep.GetWeaponInfo(this);

    if (wep.IsTypeMelee())
        return 0.0f;

    const float accuracyProg = 0.5f / wepInfo.m_fAccuracy;
    switch (wep.m_nType) {
    case eWeaponType::WEAPON_SHOTGUN:
    case eWeaponType::WEAPON_SPAS12_SHOTGUN:
    case eWeaponType::WEAPON_SAWNOFF_SHOTGUN:
        return std::max(0.2f, accuracyProg); // here they multiply *accuracyProg * 1.0f* :thinking

    default: {
        const float rangeProg = std::min(1.0f, 15.0f / wepInfo.m_fWeaponRange);
        const float radius = (m_pPlayerData->m_fAttackButtonCounter * 0.5f + 1.0f) * rangeProg * accuracyProg;
        if (bIsDucking)
            return radius / 2.0f;
        return radius;
    }
    }
}

// 0x609D90
bool CPlayerPed::PedCanBeTargettedVehicleWise(CPed* ped) {
    if (ped->bInVehicle) {
        CVehicle* veh = ped->m_pVehicle;
        return veh && (veh->IsBike() || veh->vehicleFlags.bVehicleCanBeTargetted);
    }
    return true;
}

// 0x609DE0
float CPlayerPed::FindTargetPriority(CEntity* entity) {
    switch (entity->m_nType) {
    case eEntityType::ENTITY_TYPE_VEHICLE:
        return 0.1f;

    case eEntityType::ENTITY_TYPE_PED: {
        auto ped = entity->AsPed();

        if (ped->bThisPedIsATargetPriority)
            return 1.0f;

        if (ped->GetTaskManager().FindActiveTaskByType(eTaskType::TASK_COMPLEX_KILL_PED_ON_FOOT) ||
            ped->GetTaskManager().FindActiveTaskByType(eTaskType::TASK_COMPLEX_ARREST_PED)
        ) {
            return 0.8f;
        }

        if (CPedGroups::AreInSameGroup(this, ped))
            return 0.05f;

        if (ped->m_nPedType == ePedType::PED_TYPE_GANG2)
            return 0.06f;

        if (ped->IsCreatedByMission())
            return 0.25f;

        return 0.1f;
    }

    case eEntityType::ENTITY_TYPE_OBJECT: {
        switch (entity->AsObject()->m_nObjectType) {
        case eObjectType::OBJECT_MISSION:
        case eObjectType::OBJECT_MISSION2:
            return 0.1f;

        default:
            return 0.0f;
        }
    }
    default: {
        return 0.1f;
    }
    }
}

// 0x609ED0
void CPlayerPed::Clear3rdPersonMouseTarget() {
    if (m_p3rdPersonMouseTarget) {
        m_p3rdPersonMouseTarget->CleanUpOldReference(reinterpret_cast<CEntity**>(&m_p3rdPersonMouseTarget));
        m_p3rdPersonMouseTarget = nullptr;
    }
}

// 0x609EF0
void CPlayerPed::Busted() {
    CWanted* wanted = GetWanted();
    if (wanted) {
        wanted->m_nChaosLevel = 0;
    }
}

// 0x41BE60
uint32 CPlayerPed::GetWantedLevel() {
    CWanted* wanted = GetWanted();
    if (wanted) {
        return wanted->m_nWantedLevel;
    }

    return 0;
}

// 0x609F10
void CPlayerPed::SetWantedLevel(int32 level) {
    CWanted* wanted = GetWanted();
    wanted->SetWantedLevel(level);
}

// 0x609F30
void CPlayerPed::SetWantedLevelNoDrop(int32 level) {
    CWanted* wanted = GetWanted();
    wanted->SetWantedLevelNoDrop(level);
}

// 0x609F50
void CPlayerPed::CheatWantedLevel(int32 level) {
    CWanted* wanted = GetWanted();
    wanted->CheatWantedLevel(level);
}

// 0x609F80
bool CPlayerPed::CanIKReachThisTarget(CVector posn, CWeapon* weapon, bool arg2) {
    if (!weapon->GetWeaponInfo(this).flags.bAimWithArm) {
        const CVector thisPos = GetPosition();
        return (posn - thisPos).Magnitude2D() >= thisPos.z - posn.z;
    }
    return true;
}

// 0x609FF0
CPlayerInfo* CPlayerPed::GetPlayerInfoForThisPlayerPed() {
    // TODO: Use range for here 
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (FindPlayerPed(i) == this)
            return &FindPlayerInfo(i);
    }
    return nullptr;
}

// 0x60A020
void CPlayerPed::DoStuffToGoOnFire() {
    if (m_nPedState == PEDSTATE_SNIPER_MODE)
        TheCamera.ClearPlayerWeaponMode();
}

// 0x60A040
void CPlayerPed::AnnoyPlayerPed(bool arg0) {
    auto& temper = m_pStats->m_nTemper;

    if (temper < 52) {
        temper++;
    } else if (arg0) {
        if (temper < 55)
            temper++;
        else
            temper = 46;
    }
}

// 0x60A070
void CPlayerPed::ClearAdrenaline() {
    if (m_pPlayerData->m_bAdrenaline) {
        if (m_pPlayerData->m_nAdrenalineEndTime) {
            m_pPlayerData->m_nAdrenalineEndTime = 0;
            CTimer::ResetTimeScale();
        }
    }
}

// 0x60A0A0
void CPlayerPed::DisbandPlayerGroup() {
    CPedGroupMembership& membership = GetGroupMembership();
    const uint32 nMembers = membership.CountMembersExcludingLeader();
    if (nMembers > 0)
        Say(nMembers > 1 ? 149 : 150, 0, 1.0f, 0, 0, 0);
    else
        membership.RemoveAllFollowers(true);
}

// 0x60A110
void CPlayerPed::MakeGroupRespondToPlayerTakingDamage(CEventDamage& damageEvent) {
    auto& group = GetGroup();
    if (!damageEvent.m_pSourceEntity)
        return;
    if (group.GetMembership().CountMembersExcludingLeader() < 1)
        return;
    if (!group.m_bMembersEnterLeadersVehicle)
        return;

    CEventGroupEvent groupEvent(this, damageEvent.Clone());
    group.GetIntelligence().AddEvent(&groupEvent);
}

// 0x60A1D0
void CPlayerPed::TellGroupToStartFollowingPlayer(bool arg0, bool arg1, bool arg2) {
    if (m_pPlayerData->m_bGroupAlwaysFollow && !arg0)
        return;
    if (m_pPlayerData->m_bGroupNeverFollow && arg0)
        return;

    CPedGroup& group = GetGroup();
    CPedGroupIntelligence& groupIntel = group.GetIntelligence();
    CPedGroupMembership& membership = group.GetMembership();
    if (!arg2 && !membership.CountMembersExcludingLeader())
        return;

    group.m_bMembersEnterLeadersVehicle = arg0;
    groupIntel.SetDefaultTaskAllocatorType(5); // TODO enum probably missing
    if (arg0) {
        CEventPlayerCommandToGroup playerCmdEvent;
        playerCmdEvent.ComputeResponseTaskType(&group);
        if (playerCmdEvent.WillRespond()) {
            auto gatherCmdEvent = new CEventPlayerCommandToGroup(ePlayerGroupCommand::PLAYER_GROUP_COMMAND_GATHER);
            gatherCmdEvent->m_taskId = playerCmdEvent.m_taskId;

            CEventGroupEvent groupEvent(this, gatherCmdEvent);
            groupIntel.AddEvent(&groupEvent);
        }
    }

    if (arg1) {
        const uint32 nMembers = membership.CountMembersExcludingLeader();
        if (!nMembers)
            return;

        if (arg0) {
            const float distToFurthest = group.FindDistanceToFurthestMember();
            if (nMembers > 1) {
                if (distToFurthest >= 3.0f)
                    Say(distToFurthest >= 10.0f ? 151 : 153);
                else
                    Say(155);
            } else {
                if (distToFurthest >= 3.0f)
                    Say(distToFurthest >= 10.0f ? 152 : 154);
                else
                    Say(156);
            }
        } else if (nMembers > 1) {
            Say(159);
        } else {
            Say(160);
        }
    }
}

// 0x60A440
void CPlayerPed::MakePlayerGroupDisappear() {
    CPedGroupMembership& membership = GetGroupMembership();
    for (int i = 0; i < TOTAL_PED_GROUP_FOLLOWERS; i++) {
        if (CPed* member = membership.GetMember(i)) {
            if (!member->IsCreatedByMission()) {
                member->m_bCollisionProcessed = false;
                member->m_bIsVisible = false;
                abTempNeverLeavesGroup[i] = member->bNeverLeavesGroup;
                member->bNeverLeavesGroup = true;
            }
        }
    }
}

// 0x60A4B0
void CPlayerPed::MakePlayerGroupReappear() {
    CPedGroupMembership& membership = GetGroupMembership();
    for (int i = 0; i < TOTAL_PED_GROUP_FOLLOWERS; i++) {
        if (CPed* member = membership.GetMember(i)) {
            if (!member->IsCreatedByMission()) {
                member->m_bIsVisible = true;
                if (!member->bInVehicle)
                    member->m_bUsesCollision = true;
                member->bNeverLeavesGroup = abTempNeverLeavesGroup[i];
            }
        }
    }
}

// 0x60A530
void CPlayerPed::ResetSprintEnergy()
{
    m_pPlayerData->m_fTimeCanRun = CStats::GetFatAndMuscleModifier(STAT_MOD_TIME_CAN_RUN);
}

// 0x60A550
bool CPlayerPed::HandleSprintEnergy(bool arg0, float adrenalineConsumedPerTimeStep) {
    float& timeCanRun = m_pPlayerData->m_fTimeCanRun;
    if (arg0) {
        if (FindPlayerInfo().m_bDoesNotGetTired)
            return true;
        if (m_pPlayerData->m_bAdrenaline || adrenalineConsumedPerTimeStep == 0.0f)
            return true;

        if (timeCanRun > -150.0f) { // TODO: Find out what this magic number is
            timeCanRun = std::max(-150.0f, timeCanRun - CTimer::GetTimeStep() * adrenalineConsumedPerTimeStep);
            return true;
        }
    } else {
        if (CStats::GetFatAndMuscleModifier(STAT_MOD_TIME_CAN_RUN) > timeCanRun) {
            timeCanRun += CTimer::GetTimeStep() * adrenalineConsumedPerTimeStep / 2.0f;
        }
    }
    return false;
}

constexpr auto PLAYER_SPRINT_THRESHOLD{ 5.0f }; // 0x8D2458
constexpr struct tPlayerSprintSet { // From 0x8D2460
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
} PLAYER_SPRINT_SET[] = {
    // 0x0, 0x4,  0x8,  0xC,  0x10,  0x14, 0x18, 0x1C
    { 4.0f, 0.7f, 0.2f, 5.0f, 10.0f, 1.0f, 0.5f, 0.3f }, // GROUND
    { 4.0f, 0.7f, 0.2f, 5.0f, 10.0f, 0.0f, 0.4f, 1.0f }, // BMX
    { 4.0f, 0.7f, 0.2f, 5.0f, 10.0f, 1.0f, 0.3f, 0.3f }, // WATER
    { 4.0f, 0.7f, 0.2f, 5.0f, 10.0f, 0.0f, 0.0f, 1.0f }  // UNDERWATER
};

// 0x60A610
float CPlayerPed::ControlButtonSprint(eSprintType sprintType) {
    return plugin::CallMethodAndReturn<float, 0x60A610, CPlayerPed *, eSprintType>(this, sprintType);
}

// Reverse CPlayerPed::SetRealMoveAnim before hooking this func
// 0x60A820
float CPlayerPed::GetButtonSprintResults(eSprintType sprintType) {
    return plugin::CallMethodAndReturn<float, 0x60A820, CPlayerPed *, eSprintType>(this, sprintType);

    // Forces the compiler to preserve the value of `edx`.
    // Otherwise it's value is lost when called from 0x60B44C. 
    // which causes a crash (as it is used to store a pointer to an anim blend assoc)
    __asm { and edx, edx };

    if (m_pPlayerData->m_fMoveSpeed <= PLAYER_SPRINT_THRESHOLD) {
        return m_pPlayerData->m_fMoveSpeed <= 0.0f ? 0.0f : 1.0f;
    } else {
        const float progress = std::max(0.0f, m_pPlayerData->m_fMoveSpeed / PLAYER_SPRINT_THRESHOLD - 1.0f);
        return PLAYER_SPRINT_SET[sprintType].field_1C * progress + 1.0f;
    }
}

// 0x60A8A0
void CPlayerPed::ResetPlayerBreath() {
    m_pPlayerData->m_fBreath = CStats::GetFatAndMuscleModifier(STAT_MOD_AIR_IN_LUNG);
    m_pPlayerData->m_bRequireHandleBreath = false;
}

// 0x60A8D0
void CPlayerPed::HandlePlayerBreath(bool bDecreaseAir, float fMultiplier) {
    float& breath = m_pPlayerData->m_fBreath;
    float  decreaseAmount = CTimer::GetTimeStep() * fMultiplier;
    if (!bDecreaseAir || CCheat::m_aCheatsActive[CHEAT_INFINITE_OXYGEN]) {
        breath += decreaseAmount * 2.0f;
    } else {
        if (breath > 0.0f && bDrownsInWater)
            breath = std::max(0.0f, breath - decreaseAmount);
        else
            CWeapon::GenerateDamageEvent(this, this, eWeaponType::WEAPON_DROWNING, (int32)(decreaseAmount * 3.0f), ePedPieceTypes::PED_PIECE_TORSO, 0);
    }
}

// 0x60A9C0
void CPlayerPed::SetRealMoveAnim() {
    plugin::CallMethod<0x60A9C0, CPlayerPed *>(this);
}

// 0x60B460
void CPlayerPed::MakeChangesForNewWeapon(eWeaponType weaponType) {
    GetActiveWeapon().StopWeaponEffect();
    if (m_nPedState == ePedState::PEDSTATE_SNIPER_MODE)
        TheCamera.ClearPlayerWeaponMode();

    SetCurrentWeapon(weaponType);

    m_pPlayerData->m_nChosenWeapon = m_nActiveWeaponSlot;
    m_pPlayerData->m_fAttackButtonCounter= 0.0f;

    CWeapon& wep = GetActiveWeapon();
    CWeaponInfo& wepInfo = wep.GetWeaponInfo(this);

    wep.m_nAmmoInClip = std::min<uint32>(wep.m_nTotalAmmo, (uint32)wepInfo.m_nAmmoClip);

    if (!wepInfo.flags.bCanAim)
        ClearWeaponTarget();

    if (!wepInfo.flags.bOnlyFreeAim)
        m_pPlayerData->m_bFreeAiming = false;


    if (auto anim = RpAnimBlendClumpGetAssociation(m_pRwClump, AnimationId::ANIM_ID_FIRE))
        anim->m_nFlags |= ANIM_FLAG_STARTED & ANIM_FLAG_UNLOCK_LAST_FRAME;

    TheCamera.ClearPlayerWeaponMode();
}

// 0x60B550
bool LOSBlockedBetweenPeds(CEntity* entity1, CEntity* entity2) {
    CVector origin{};
    if (entity1->IsPed()) {
        entity1->AsPed()->GetBonePosition(origin, ePedBones::BONE_NECK, false);
        if (entity1->AsPed()->bIsDucking)
            origin.z += 0.35f;
    } else {
        origin = entity1->GetPosition();
    }

    CVector target{};
    if (entity2->IsPed())
        entity1->AsPed()->GetBonePosition(target, ePedBones::BONE_NECK, false);
    else
        target = entity1->GetPosition();

    CColPoint colPoint;
    CEntity* hitEntity;
    if (CWorld::ProcessLineOfSight(origin, target, colPoint, hitEntity, true, false, false, true, false, false, false, true))
        return hitEntity != entity2;
    return false;
}

// 0x60B650
void CPlayerPed::Compute3rdPersonMouseTarget(bool meleeWeapon) {
    plugin::CallMethod<0x60B650, CPlayerPed *, bool>(this, meleeWeapon);
}

// 0x60BA80
void CPlayerPed::DrawTriangleForMouseRecruitPed() {
    plugin::CallMethod<0x60BA80, CPlayerPed *>(this);
}

// 0x60C0C0
bool CPlayerPed::DoesTargetHaveToBeBroken(CEntity* entity, CWeapon* weapon) {
    if (entity->m_bIsVisible)
        return true;

    if (weapon->GetWeaponInfo(this).m_fTargetRange < (entity->GetPosition() - GetPosition()).Magnitude())
        return true;

    if (weapon->m_nType == eWeaponType::WEAPON_SPRAYCAN) {
        if (entity->m_nType == eEntityType::ENTITY_TYPE_BUILDING) {
            if (CTagManager::IsTag(entity)) {
                if (CTagManager::GetAlpha(entity) == 255) { // they probably used -1
                    return true;
                }
            }
        }
    }

    return CanIKReachThisTarget(entity->GetPosition(), weapon, false);
}

// 0x60C1E0
void CPlayerPed::KeepAreaAroundPlayerClear() {
    plugin::CallMethod<0x60C1E0, CPlayerPed *>(this);
}

// 0x60C520
void CPlayerPed::SetPlayerMoveBlendRatio(CVector* point) {
    float& moveBlendRatio = m_pPlayerData->m_fMoveBlendRatio;
    if (point) {
        moveBlendRatio = std::min(2.0f, (*point - GetPosition()).Magnitude2D() * 2.0f);
    } else {
        switch (m_nMoveState)
        {
        case PEDMOVE_WALK:
            moveBlendRatio = 1.0f;
            break;

        case PEDMOVE_RUN:
            moveBlendRatio = 1.8f;
            break;

        case PEDMOVE_SPRINT:
            moveBlendRatio = 2.5f;
            break;

        default:
            moveBlendRatio = 0.0f;
            break;
        }
    }
    SetRealMoveAnim();
}

// 0x60C5F0
CPed* CPlayerPed::FindPedToAttack() {
    CVector origin = FindPlayerCoors();
    origin.z = 0.0f;

    CVector end = origin + TheCamera.GetForward() * 100.0f;
    end.z = 0.0f;

    CPed* closestPed{};
    float closestDistance = std::numeric_limits<float>::max();

    CPedGroupMembership& membership = GetGroupMembership();
    for (int i = 0; CPools::ms_pPedPool->GetSize(); i++) {
        CPed* ped = CPools::ms_pPedPool->GetAt(i);
        if (!ped)
            continue;
        if (ped->IsPlayer())
            continue;
        if (!ped->IsAlive())
            continue;
        if (membership.IsMember(ped))
            continue;
        if (ped->m_nPedType == ePedType::PED_TYPE_GANG2)
            continue;

        CVector point = ped->GetPosition();
        point.z = 0.0f;

        float dist = CCollision::DistToLine(origin, end, point);
        float pointDist = (point - origin).Magnitude2D();
        if (pointDist > 20.0f)
            dist += (pointDist - 20.0f) / 5.0f;

        if (IsPedTypeGang(ped->m_nPedType))
            dist = std::max(0.0f, dist / 2.0f - 2.0f);

        if (dist < closestDistance) {
            closestDistance = dist;
            closestPed = ped;
        }
    }
    return closestPed;
}

// 0x60C7C0
void CPlayerPed::ForceGroupToAlwaysFollow(bool enable) {
    m_pPlayerData->m_bGroupAlwaysFollow = enable;
    if (enable)
        TellGroupToStartFollowingPlayer(true, false, true);
}

// 0x60C800
void CPlayerPed::ForceGroupToNeverFollow(bool enable) {
    m_pPlayerData->m_bGroupNeverFollow = enable;
    if (enable)
        TellGroupToStartFollowingPlayer(false, false, true);
}

// 0x60C840
void CPlayerPed::MakeThisPedJoinOurGroup(CPed* ped) {
    plugin::CallMethod<0x60C840, CPlayerPed *, CPed*>(this, ped);
}

// 0x60CC50
bool CPlayerPed::PlayerWantsToAttack() {
    return plugin::CallMethodAndReturn<bool, 0x60CC50, CPlayerPed *>(this);
}

// 0x60CD20
void CPlayerPed::SetInitialState(bool bGroupCreated) {
    plugin::CallMethod<0x60CD20, CPlayerPed *, bool>(this, bGroupCreated);
}

// 0x60D000
void CPlayerPed::MakeChangesForNewWeapon(uint32 weaponSlot) {
    if (weaponSlot != -1)
        MakeChangesForNewWeapon(GetWeaponInSlot(weaponSlot).m_nType);
}

static auto& PLAYER_MAX_TARGET_VIEW_ANGLE = *(float*)0x8D243C; // 140.0f

// 0x60D020
void CPlayerPed::EvaluateTarget(CEntity* target, CEntity *& outTarget, float & outTargetPriority, float maxDistance, float compensationRotRad, bool arg5) {
    const CVector dir = target->GetPosition() - GetPosition();
    const float dist = dir.Magnitude();

    if (dist > maxDistance)
        return;

    if (DoesTargetHaveToBeBroken(target, &GetActiveWeapon()))
        return;

    const float targetAngleDeg = fabs(RWRAD2DEG(CGeneral::LimitRadianAngle(CGeneral::GetATanOf(dir) - compensationRotRad)));

    float viewAngleMultiplier = 1.0f - targetAngleDeg / PLAYER_MAX_TARGET_VIEW_ANGLE;
    if (dist > 1.0f)
        viewAngleMultiplier /= sqrt(sqrt(dist)); // Take quad root of dist

    const float targetPriority = FindTargetPriority(target) * viewAngleMultiplier;
    if (targetPriority > outTargetPriority && !LOSBlockedBetweenPeds(this, target)) {
        outTarget = target;
        outTargetPriority = targetPriority;
    }
}

// 0x60D1C0
void CPlayerPed::EvaluateNeighbouringTarget(CEntity* target, CEntity** outTarget, float* outTargetPriority, float maxDistance, float arg4, bool arg5) {
    plugin::CallMethod<0x60D1C0, CPlayerPed *, CEntity*, CEntity**, float*, float, float, bool>(this, target, outTarget, outTargetPriority, maxDistance, arg4, arg5);
}

// 0x60D350
void CPlayerPed::ProcessGroupBehaviour(CPad* pad) {
    plugin::CallMethod<0x60D350, CPlayerPed *, CPad*>(this, pad);
}

// 0x60D5A0
bool CPlayerPed::PlayerHasJustAttackedSomeone() {
    return PlayerWantsToAttack();
}

// 0x60D790
void CPlayerPed::SetupPlayerPed(int32 playerId) {
    auto ped = new CPlayerPed(playerId, false);
    auto& playerInfo = FindPlayerInfo(playerId);
    playerInfo.m_pPed = ped;

    if (playerId == 1)
        ped->m_nPedType = ePedType::PED_TYPE_PLAYER2;

    ped->SetOrientation(0.0f, 0.0f, 0.0f);
    CWorld::Add(ped);
    ped->m_nWeaponAccuracy = 100;
    playerInfo.m_nPlayerState = ePlayerState::PLAYERSTATE_PLAYING;
}

// 0x60D850
void CPlayerPed::ProcessWeaponSwitch(CPad* pad) {
    plugin::CallMethod<0x60D850, CPlayerPed *, CPad*>(this, pad);
}

// 0x60DC50
bool CPlayerPed::FindWeaponLockOnTarget() {
    return plugin::CallMethodAndReturn<bool, 0x60DC50, CPlayerPed *>(this);
}

// 0x60E530
bool CPlayerPed::FindNextWeaponLockOnTarget(CEntity* arg0, bool arg1) {
    return plugin::CallMethodAndReturn<bool, 0x60E530, CPlayerPed *, CEntity*, bool>(this, arg0, arg1);
}