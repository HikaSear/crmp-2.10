//
// Fixed by vadim on 31.05.2025.
//

#ifndef SKYBOX_H
#define SKYBOX_H

#include "main.h"

class CObject;

class CSkyBox {
public:
    static void Process();
    static bool is;
private:
    static CObject* m_pSkyBox;
    static RpAtomic* ObjectMaterialCallBackEdgar(RpAtomic* rpAtomic, CObject* pObject);
    static void RwPon();
};

#endif // SKYBOX_H