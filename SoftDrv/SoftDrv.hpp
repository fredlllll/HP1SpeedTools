#pragma once
#include <string>
#include <Windows.h>

//TODO: find lnk file for unreal?
/*class FName;
class UObject;
class UClass;
class FVector;
class FPlane;
class FSpanBuffer;
class FOutputDevice;
class UViewport;
class FColor;
struct FSceneNode;
struct FMipmapBase;
struct FSceneNode;
struct FSurfaceInfo;
struct FSurfaceFacet;
struct FTextureInfo;
struct FTransTexture;
enum EInternal;*/

class FOutputDevice;

class USoftwareRenderDevice {
public:
	/*USoftwareRenderDevice(USoftwareRenderDevice const &other);
	USoftwareRenderDevice(void);
	virtual ~USoftwareRenderDevice(void);

	static void * __cdecl operator new(unsigned int a, UObject *b, FName c, unsigned long d);
	static void * __cdecl operator new(unsigned int a, EInternal * b);
	class USoftwareRenderDevice & __thiscall operator=(USoftwareRenderDevice const &other);

	virtual void __thiscall USoftwareRenderDevice::ClearZ(FSceneNode *);
	virtual void __thiscall USoftwareRenderDevice::Draw2DLine(FSceneNode *, FPlane, unsigned long, FVector, class FVector);
	virtual void __thiscall USoftwareRenderDevice::Draw2DPoint(FSceneNode *, FPlane, unsigned long, float, float, float, float, float);
	virtual void __thiscall USoftwareRenderDevice::DrawComplexSurface(struct FSceneNode *, struct FSurfaceInfo &, struct FSurfaceFacet &);
	virtual void __thiscall USoftwareRenderDevice::DrawTile(struct FSceneNode *, struct FTextureInfo &, float, float, float, float, float, float, float, float, class FSpanBuffer *, float, class FPlane, class FPlane, unsigned long);
	virtual void __thiscall USoftwareRenderDevice::DrawTriangles(struct FSceneNode *, struct FTextureInfo &, struct FTransTexture * *, int, unsigned short *, int, unsigned long, class FSpanBuffer *);
	*/
	virtual int __thiscall USoftwareRenderDevice::Exec(unsigned short const *eh, FOutputDevice &device);
	/*virtual void __thiscall USoftwareRenderDevice::Exit(void);
	virtual void __thiscall USoftwareRenderDevice::Flush(int);
	virtual void __thiscall USoftwareRenderDevice::GetStats(unsigned short *);
	virtual int __thiscall USoftwareRenderDevice::Init(class UViewport *, int, int, int, int);
	static void __cdecl USoftwareRenderDevice::InternalConstructor(void *);
	virtual void __thiscall USoftwareRenderDevice::Lock(class FPlane, class FPlane, class FPlane, unsigned long, unsigned char *, int *);
	virtual int __thiscall USoftwareRenderDevice::MaxVertices(void);
	virtual void __thiscall USoftwareRenderDevice::PopHit(int, int);
	virtual void __thiscall USoftwareRenderDevice::PushHit(unsigned char const *, int);
	virtual void __thiscall USoftwareRenderDevice::ReadPixels(class FColor *);
	virtual int __thiscall USoftwareRenderDevice::SetRes(int, int, int, int);
	static class UClass * __cdecl USoftwareRenderDevice::StaticClass(void);

	void __thiscall USoftwareRenderDevice::StaticConstructor(void);
	virtual void __thiscall USoftwareRenderDevice::Unlock(int);
private:
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);

	void __thiscall BlitAlpha15(class FSpanBuffer *);
	void __thiscall BlitAlpha16(class FSpanBuffer *);
	void __thiscall BlitAlpha32(class FSpanBuffer *);
	void __thiscall BlitMask1516(class FSpanBuffer *);
	void __thiscall BlitMask32(class FSpanBuffer *);
	void __thiscall BlitTile1516(class FSpanBuffer *);
	void __thiscall BlitTile32(class FSpanBuffer *);
	void __thiscall ClearScreenFast16(unsigned short *, unsigned long);
	void __thiscall ClearScreenFast32(unsigned long *, unsigned long);
	void __thiscall InitColorTables(float, int, unsigned long);
	void __thiscall InitDrawSurf(void);
	void __thiscall InitMMXFlashes(float, int, unsigned long);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall MMXFlashTriangle(struct FSceneNode *, struct FTextureInfo &, unsigned long, class FSpanBuffer *);
	void __thiscall PentiumFlashTriangle(struct FSceneNode *, struct FTextureInfo &, unsigned long, class FSpanBuffer *);
	static class UClass PrivateStaticClass();
	void __thiscall RenderSurfSpansMMX15(union FRainbowPtr &, struct FSurfaceInfo &, int, int);
	void __thiscall RenderSurfSpansMMX16(union FRainbowPtr &, struct FSurfaceInfo &, int, int);
	void __thiscall RenderSurfSpansMMX32(union FRainbowPtr &, struct FSurfaceInfo &, int, int);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX15(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX16(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	void __thiscall InnerGouraudMMX32(unsigned long, int, int, struct FSceneNode *, struct FMipmapBase *, class FSpanBuffer *);
	// _DllMain@12; Index 72;		Information not available
	// GPackage; Index 73;			Information not available
	// autoclassUSoftwareRenderDevice; Index 74;	Information not available*/
};

// ??0USoftwareRenderDevice@@QAE@ABV0@@Z; Index 1;	Undecorated C++ Function: public: __thiscall USoftwareRenderDevice::USoftwareRenderDevice(class USoftwareRenderDevice const &)

// ??0USoftwareRenderDevice@@QAE@XZ; Index 2;	Undecorated C++ Function: public: __thiscall USoftwareRenderDevice::USoftwareRenderDevice(void)

// ??1USoftwareRenderDevice@@UAE@XZ; Index 3;	Undecorated C++ Function: public: virtual __thiscall USoftwareRenderDevice::~USoftwareRenderDevice(void)

// ??2USoftwareRenderDevice@@SAPAXIPAVUObject@@VFName@@K@Z; Index 4;	Undecorated C++ Function: public: static void * __cdecl USoftwareRenderDevice::operator new(unsigned int,class UObject *,class FName,unsigned long)

// ??2USoftwareRenderDevice@@SAPAXIPAW4EInternal@@@Z; Index 5;	Undecorated C++ Function: public: static void * __cdecl USoftwareRenderDevice::operator new(unsigned int,enum EInternal *)

// ??4USoftwareRenderDevice@@QAEAAV0@ABV0@@Z; Index 6;	Undecorated C++ Function: public: class USoftwareRenderDevice & __thiscall USoftwareRenderDevice::operator=(class USoftwareRenderDevice const &)

// ??_7USoftwareRenderDevice@@6BFExec@@@; Index 7;	Undecorated C++ Function: const USoftwareRenderDevice::`vftable'{for `FExec'}

// ??_7USoftwareRenderDevice@@6BUObject@@@; Index 8;	Undecorated C++ Function: const USoftwareRenderDevice::`vftable'{for `UObject'}

// ??_B?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@51; Index 9;	Undecorated C++ Function: `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::`local static guard'{2}'

// ??_B?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@51; Index 10;	Undecorated C++ Function: `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::`local static guard'{2}'

// ??_B?1??InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@51; Index 11;	Undecorated C++ Function: `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::`local static guard'{2}'

// ?BlitAlpha15@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 12;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitAlpha15(class FSpanBuffer *)

// ?BlitAlpha16@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 13;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitAlpha16(class FSpanBuffer *)

// ?BlitAlpha32@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 14;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitAlpha32(class FSpanBuffer *)

// ?BlitMask1516@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 15;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitMask1516(class FSpanBuffer *)

// ?BlitMask32@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 16;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitMask32(class FSpanBuffer *)

// ?BlitTile1516@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 17;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitTile1516(class FSpanBuffer *)

// ?BlitTile32@USoftwareRenderDevice@@AAEXPAVFSpanBuffer@@@Z; Index 18;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::BlitTile32(class FSpanBuffer *)

// ?ClearScreenFast16@USoftwareRenderDevice@@AAEXPAGK@Z; Index 19;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::ClearScreenFast16(unsigned short *,unsigned long)

// ?ClearScreenFast32@USoftwareRenderDevice@@AAEXPAKK@Z; Index 20;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::ClearScreenFast32(unsigned long *,unsigned long)

// ?ClearZ@USoftwareRenderDevice@@UAEXPAUFSceneNode@@@Z; Index 21;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::ClearZ(struct FSceneNode *)

// ?Draw2DLine@USoftwareRenderDevice@@UAEXPAUFSceneNode@@VFPlane@@KVFVector@@2@Z; Index 22;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Draw2DLine(struct FSceneNode *,class FPlane,unsigned long,class FVector,class FVector)

// ?Draw2DPoint@USoftwareRenderDevice@@UAEXPAUFSceneNode@@VFPlane@@KMMMMM@Z; Index 23;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Draw2DPoint(struct FSceneNode *,class FPlane,unsigned long,float,float,float,float,float)

// ?DrawComplexSurface@USoftwareRenderDevice@@UAEXPAUFSceneNode@@AAUFSurfaceInfo@@AAUFSurfaceFacet@@@Z; Index 24;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::DrawComplexSurface(struct FSceneNode *,struct FSurfaceInfo &,struct FSurfaceFacet &)

// ?DrawTile@USoftwareRenderDevice@@UAEXPAUFSceneNode@@AAUFTextureInfo@@MMMMMMMMPAVFSpanBuffer@@MVFPlane@@3K@Z; Index 25;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::DrawTile(struct FSceneNode *,struct FTextureInfo &,float,float,float,float,float,float,float,float,class FSpanBuffer *,float,class FPlane,class FPlane,unsigned long)

// ?DrawTriangles@USoftwareRenderDevice@@UAEXPAUFSceneNode@@AAUFTextureInfo@@PAPAUFTransTexture@@HPAGHKPAVFSpanBuffer@@@Z; Index 26;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::DrawTriangles(struct FSceneNode *,struct FTextureInfo &,struct FTransTexture * *,int,unsigned short *,int,unsigned long,class FSpanBuffer *)

// ?Exec@USoftwareRenderDevice@@UAEHPBGAAVFOutputDevice@@@Z; Index 27;	Undecorated C++ Function: public: virtual int __thiscall USoftwareRenderDevice::Exec(unsigned short const *,class FOutputDevice &)

// ?Exit@USoftwareRenderDevice@@UAEXXZ; Index 28;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Exit(void)

// ?Flush@USoftwareRenderDevice@@UAEXH@Z; Index 29;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Flush(int)

// ?GetStats@USoftwareRenderDevice@@UAEXPAG@Z; Index 30;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::GetStats(unsigned short *)

// ?Init@USoftwareRenderDevice@@UAEHPAVUViewport@@HHHH@Z; Index 31;	Undecorated C++ Function: public: virtual int __thiscall USoftwareRenderDevice::Init(class UViewport *,int,int,int,int)

// ?InitColorTables@USoftwareRenderDevice@@AAEXMHK@Z; Index 32;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InitColorTables(float,int,unsigned long)

// ?InitDrawSurf@USoftwareRenderDevice@@AAEXXZ; Index 33;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InitDrawSurf(void)

// ?InitMMXFlashes@USoftwareRenderDevice@@AAEXMHK@Z; Index 34;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InitMMXFlashes(float,int,unsigned long)

// ?InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z; Index 35;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)

// ?InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z; Index 36;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)

// ?InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z; Index 37;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)

// ?InternalConstructor@USoftwareRenderDevice@@SAXPAX@Z; Index 38;	Undecorated C++ Function: public: static void __cdecl USoftwareRenderDevice::InternalConstructor(void *)

// ?Lock@USoftwareRenderDevice@@UAEXVFPlane@@00KPAEPAH@Z; Index 39;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Lock(class FPlane,class FPlane,class FPlane,unsigned long,unsigned char *,int *)

// ?MMX15GREEN@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 40;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX15GREEN

// ?MMX15MULFACT@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 41;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX15MULFACT

// ?MMX15REDBLUE@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 42;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX15REDBLUE

// ?MMX16GREEN@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 43;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX16GREEN

// ?MMX16MULFACT@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 44;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX16MULFACT

// ?MMX16REDBLUE@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 45;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMX16REDBLUE

// ?MMXCoMask@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 46;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoMask

// ?MMXCoMask@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 47;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoMask

// ?MMXCoMask@?1??InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 48;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoMask

// ?MMXCoShift@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 49;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoShift

// ?MMXCoShift@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 50;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoShift

// ?MMXCoShift@?1??InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFMMX@@A; Index 51;	Undecorated C++ Function: union FMMX `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::MMXCoShift

// ?MMXFlashTriangle@USoftwareRenderDevice@@AAEXPAUFSceneNode@@AAUFTextureInfo@@KPAVFSpanBuffer@@@Z; Index 52;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::MMXFlashTriangle(struct FSceneNode *,struct FTextureInfo &,unsigned long,class FSpanBuffer *)

// ?MaxVertices@USoftwareRenderDevice@@UAEHXZ; Index 53;	Undecorated C++ Function: public: virtual int __thiscall USoftwareRenderDevice::MaxVertices(void)

// ?PentiumFlashTriangle@USoftwareRenderDevice@@AAEXPAUFSceneNode@@AAUFTextureInfo@@KPAVFSpanBuffer@@@Z; Index 54;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::PentiumFlashTriangle(struct FSceneNode *,struct FTextureInfo &,unsigned long,class FSpanBuffer *)

// ?PopHit@USoftwareRenderDevice@@UAEXHH@Z; Index 55;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::PopHit(int,int)

// ?PrivateStaticClass@USoftwareRenderDevice@@0VUClass@@A; Index 56;	Undecorated C++ Function: private: static class UClass USoftwareRenderDevice::PrivateStaticClass

// ?PushHit@USoftwareRenderDevice@@UAEXPBEH@Z; Index 57;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::PushHit(unsigned char const *,int)

// ?ReadPixels@USoftwareRenderDevice@@UAEXPAVFColor@@@Z; Index 58;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::ReadPixels(class FColor *)

// ?RenderSurfSpansMMX15@USoftwareRenderDevice@@AAEXAATFRainbowPtr@@AAUFSurfaceInfo@@HH@Z; Index 59;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::RenderSurfSpansMMX15(union FRainbowPtr &,struct FSurfaceInfo &,int,int)

// ?RenderSurfSpansMMX16@USoftwareRenderDevice@@AAEXAATFRainbowPtr@@AAUFSurfaceInfo@@HH@Z; Index 60;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::RenderSurfSpansMMX16(union FRainbowPtr &,struct FSurfaceInfo &,int,int)

// ?RenderSurfSpansMMX32@USoftwareRenderDevice@@AAEXAATFRainbowPtr@@AAUFSurfaceInfo@@HH@Z; Index 61;	Undecorated C++ Function: private: void __thiscall USoftwareRenderDevice::RenderSurfSpansMMX32(union FRainbowPtr &,struct FSurfaceInfo &,int,int)

// ?Screen@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFRainbowPtr@@A; Index 62;	Undecorated C++ Function: union FRainbowPtr `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::Screen

// ?Screen@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFRainbowPtr@@A; Index 63;	Undecorated C++ Function: union FRainbowPtr `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::Screen

// ?Screen@?1??InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4TFRainbowPtr@@A; Index 64;	Undecorated C++ Function: union FRainbowPtr `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::Screen

// ?SetRes@USoftwareRenderDevice@@UAEHHHHH@Z; Index 65;	Undecorated C++ Function: public: virtual int __thiscall USoftwareRenderDevice::SetRes(int,int,int,int)

// ?StaticClass@USoftwareRenderDevice@@SAPAVUClass@@XZ; Index 66;	Undecorated C++ Function: public: static class UClass * __cdecl USoftwareRenderDevice::StaticClass(void)

// ?StaticConstructor@USoftwareRenderDevice@@QAEXXZ; Index 67;	Undecorated C++ Function: public: void __thiscall USoftwareRenderDevice::StaticConstructor(void)

// ?TexBase@?1??InnerGouraudMMX15@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4PAEA; Index 68;	Undecorated C++ Function: unsigned char * `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX15(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::TexBase

// ?TexBase@?1??InnerGouraudMMX16@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4PAEA; Index 69;	Undecorated C++ Function: unsigned char * `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX16(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::TexBase

// ?TexBase@?1??InnerGouraudMMX32@USoftwareRenderDevice@@AAEXKHHPAUFSceneNode@@PAUFMipmapBase@@PAVFSpanBuffer@@@Z@4PAEA; Index 70;	Undecorated C++ Function: unsigned char * `private: void __thiscall USoftwareRenderDevice::InnerGouraudMMX32(unsigned long,int,int,struct FSceneNode *,struct FMipmapBase *,class FSpanBuffer *)'::`2'::TexBase

// ?Unlock@USoftwareRenderDevice@@UAEXH@Z; Index 71;	Undecorated C++ Function: public: virtual void __thiscall USoftwareRenderDevice::Unlock(int)

// _DllMain@12; Index 72;		Information not available

// GPackage; Index 73;			Information not available

// autoclassUSoftwareRenderDevice; Index 74;	Information not available