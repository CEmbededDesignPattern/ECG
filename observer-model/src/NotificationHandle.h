#if !defined(_NOTIFICATIONHANDLE_H)
#define _NOTIFICATIONHANDLE_H
#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

typedef void (*UpdateFuncPtr) (void *, TimeMarkedData);

typedef struct NotificationHandle NotificationHandle;
struct NotificationHandle {
    UpdateFuncPtr updateAddr;
    struct NotificationHandle *itsNotificationHandle;
};


/* Constructors and Destructors */
void NotificationHandle_Init(NotificationHandle *const me);
void NotificationHandle_Cleanup(NotificationHandle *const me);

struct NotificationHandle *NotificationHandle_getItsNotificationHandle(const NotificationHandle *const me);
void NotificationHandle_setItsNotificationHandle(NotificationHandle *const me, struct NotificationHandle *p_NotificationHandle);

NotificationHandle *NotificationHandle_Create(void);
void NotificationHandle_Destroy(NotificationHandle *const me);

#endif // _NOTIFICATIONHANDLE_H
