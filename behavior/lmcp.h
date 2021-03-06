#pragma once
#include "struct_defines.h"
#include "AbstractGeometry.h"
#include "KeyValuePair.h"
#include "Location3D.h"
#include "PayloadAction.h"
#include "PayloadConfiguration.h"
#include "PayloadState.h"
#include "VehicleAction.h"
#include "Task.h"
#include "SearchTask.h"
#include "AbstractZone.h"
#include "EntityConfiguration.h"
#include "FlightProfile.h"
#include "AirVehicleConfiguration.h"
#include "EntityState.h"
#include "AirVehicleState.h"
#include "Wedge.h"
#include "AreaSearchTask.h"
#include "CameraAction.h"
#include "CameraConfiguration.h"
#include "GimballedPayloadState.h"
#include "CameraState.h"
#include "Circle.h"
#include "GimbalAngleAction.h"
#include "GimbalConfiguration.h"
#include "GimbalScanAction.h"
#include "GimbalStareAction.h"
#include "GimbalState.h"
#include "GoToWaypointAction.h"
#include "KeepInZone.h"
#include "KeepOutZone.h"
#include "LineSearchTask.h"
#include "NavigationAction.h"
#include "LoiterAction.h"
#include "LoiterTask.h"
#include "Waypoint.h"
#include "MissionCommand.h"
#include "MustFlyTask.h"
#include "OperatorSignal.h"
#include "OperatingRegion.h"
#include "AutomationRequest.h"
#include "PointSearchTask.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "RemoveTasks.h"
#include "ServiceStatus.h"
#include "SessionStatus.h"
#include "VehicleActionCommand.h"
#include "VideoStreamAction.h"
#include "VideoStreamConfiguration.h"
#include "VideoStreamState.h"
#include "AutomationResponse.h"
#include "RemoveZones.h"
#include "RemoveEntities.h"
#include "FlightDirectorAction.h"
#include "WeatherReport.h"
#include "FollowPathCommand.h"
#include "PathWaypoint.h"
#include "StopMovementAction.h"
#include "WaypointTransfer.h"
#include "PayloadStowAction.h"
void lmcp_pp(lmcp_object* o);
uint32_t lmcp_msgsize(lmcp_object* o);
uint32_t lmcp_packsize(lmcp_object* o);
void lmcp_free(lmcp_object* o);
void lmcp_make_msg(uint8_t* buf, lmcp_object *o);
int lmcp_process_msg(uint8_t** inb, size_t size, lmcp_object **o);
int lmcp_unpack(uint8_t** inb, size_t size, lmcp_object **o);
uint32_t lmcp_pack(uint8_t* buf, lmcp_object* o);
