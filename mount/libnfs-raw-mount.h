/*
Copyright (c) 2014, Ronnie Sahlberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MOUNT_H_RPCGEN
#define _MOUNT_H_RPCGEN

#include <nfsc/libnfs-zdr.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MNTPATHLEN 1024
#define MNTNAMLEN 255
#define FHSIZE3 64

typedef struct {
	u_int fhandle3_len;
	char *fhandle3_val;
} fhandle3;

typedef char *dirpath;

typedef char *name;

enum mountstat3 {
	MNT3_OK = 0,
	MNT3ERR_PERM = 1,
	MNT3ERR_NOENT = 2,
	MNT3ERR_IO = 5,
	MNT3ERR_ACCES = 13,
	MNT3ERR_NOTDIR = 20,
	MNT3ERR_INVAL = 22,
	MNT3ERR_NAMETOOLONG = 63,
	MNT3ERR_NOTSUPP = 10004,
	MNT3ERR_SERVERFAULT = 10006,
};
typedef enum mountstat3 mountstat3;

typedef struct mountbody *mountlist;

struct mountbody {
	name ml_hostname;
	dirpath ml_directory;
	mountlist ml_next;
};
typedef struct mountbody mountbody;

typedef struct groupnode *groups;

struct groupnode {
	name gr_name;
	groups gr_next;
};
typedef struct groupnode groupnode;

typedef struct exportnode *exports;

struct exportnode {
	dirpath ex_dir;
	groups ex_groups;
	exports ex_next;
};
typedef struct exportnode exportnode;

struct mountres3_ok {
	fhandle3 fhandle;
	struct {
		uint32_t auth_flavors_len;
		int *auth_flavors_val;
	} auth_flavors;
};
typedef struct mountres3_ok mountres3_ok;

struct mountres3 {
	mountstat3 fhs_status;
	union {
		mountres3_ok mountinfo;
	} mountres3_u;
};
typedef struct mountres3 mountres3;

enum mountstat1 {
	MNT1_OK = 0,
	MNT1ERR_PERM = 1,
	MNT1ERR_NOENT = 2,
	MNT1ERR_IO = 5,
	MNT1ERR_ACCES = 13,
	MNT1ERR_NOTDIR = 20,
	MNT1ERR_INVAL = 22,
	MNT1ERR_NAMETOOLONG = 63,
	MNT1ERR_NOTSUPP = 10004,
	MNT1ERR_SERVERFAULT = 10006,
};
typedef enum mountstat1 mountstat1;
#define FHSIZE 32

typedef char fhandle1[FHSIZE];

struct mountres1_ok {
	fhandle1 fhandle;
};
typedef struct mountres1_ok mountres1_ok;

struct mountres1 {
	mountstat1 fhs_status;
	union {
		mountres1_ok mountinfo;
	} mountres1_u;
};
typedef struct mountres1 mountres1;

#define MOUNT_PROGRAM 100005
#define MOUNT_V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define MOUNT1_NULL 0
extern  void * mount1_null_1(void *, void *);
extern  void * mount1_null_1_svc(void *, struct svc_req *);
#define MOUNT1_MNT 1
extern  mountres1 * mount1_mnt_1(dirpath *, void *);
extern  mountres1 * mount1_mnt_1_svc(dirpath *, struct svc_req *);
#define MOUNT1_DUMP 2
extern  mountlist * mount1_dump_1(void *, void *);
extern  mountlist * mount1_dump_1_svc(void *, struct svc_req *);
#define MOUNT1_UMNT 3
extern  void * mount1_umnt_1(dirpath *, void *);
extern  void * mount1_umnt_1_svc(dirpath *, struct svc_req *);
#define MOUNT1_UMNTALL 4
extern  void * mount1_umntall_1(void *, void *);
extern  void * mount1_umntall_1_svc(void *, struct svc_req *);
#define MOUNT1_EXPORT 5
extern  exports * mount1_export_1(void *, void *);
extern  exports * mount1_export_1_svc(void *, struct svc_req *);
extern int mount_program_1_freeresult (void *, zdrproc_t, caddr_t);

#else /* K&R C */
#define MOUNT1_NULL 0
extern  void * mount1_null_1();
extern  void * mount1_null_1_svc();
#define MOUNT1_MNT 1
extern  mountres1 * mount1_mnt_1();
extern  mountres1 * mount1_mnt_1_svc();
#define MOUNT1_DUMP 2
extern  mountlist * mount1_dump_1();
extern  mountlist * mount1_dump_1_svc();
#define MOUNT1_UMNT 3
extern  void * mount1_umnt_1();
extern  void * mount1_umnt_1_svc();
#define MOUNT1_UMNTALL 4
extern  void * mount1_umntall_1();
extern  void * mount1_umntall_1_svc();
#define MOUNT1_EXPORT 5
extern  exports * mount1_export_1();
extern  exports * mount1_export_1_svc();
extern int mount_program_1_freeresult ();
#endif /* K&R C */
#define MOUNT_V3 3

#if defined(__STDC__) || defined(__cplusplus)
#define MOUNT3_NULL 0
extern  void * mount3_null_3(void *, void *);
extern  void * mount3_null_3_svc(void *, struct svc_req *);
#define MOUNT3_MNT 1
extern  mountres3 * mount3_mnt_3(dirpath *, void *);
extern  mountres3 * mount3_mnt_3_svc(dirpath *, struct svc_req *);
#define MOUNT3_DUMP 2
extern  mountlist * mount3_dump_3(void *, void *);
extern  mountlist * mount3_dump_3_svc(void *, struct svc_req *);
#define MOUNT3_UMNT 3
extern  void * mount3_umnt_3(dirpath *, void *);
extern  void * mount3_umnt_3_svc(dirpath *, struct svc_req *);
#define MOUNT3_UMNTALL 4
extern  void * mount3_umntall_3(void *, void *);
extern  void * mount3_umntall_3_svc(void *, struct svc_req *);
#define MOUNT3_EXPORT 5
extern  exports * mount3_export_3(void *, void *);
extern  exports * mount3_export_3_svc(void *, struct svc_req *);
extern int mount_program_3_freeresult (void *, zdrproc_t, caddr_t);

#else /* K&R C */
#define MOUNT3_NULL 0
extern  void * mount3_null_3();
extern  void * mount3_null_3_svc();
#define MOUNT3_MNT 1
extern  mountres3 * mount3_mnt_3();
extern  mountres3 * mount3_mnt_3_svc();
#define MOUNT3_DUMP 2
extern  mountlist * mount3_dump_3();
extern  mountlist * mount3_dump_3_svc();
#define MOUNT3_UMNT 3
extern  void * mount3_umnt_3();
extern  void * mount3_umnt_3_svc();
#define MOUNT3_UMNTALL 4
extern  void * mount3_umntall_3();
extern  void * mount3_umntall_3_svc();
#define MOUNT3_EXPORT 5
extern  exports * mount3_export_3();
extern  exports * mount3_export_3_svc();
extern int mount_program_3_freeresult ();
#endif /* K&R C */

/* the zdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  uint32_t zdr_fhandle3 (ZDR *, fhandle3*);
extern  uint32_t zdr_dirpath (ZDR *, dirpath*);
extern  uint32_t zdr_name (ZDR *, name*);
extern  uint32_t zdr_mountstat3 (ZDR *, mountstat3*);
extern  uint32_t zdr_mountlist (ZDR *, mountlist*);
extern  uint32_t zdr_mountbody (ZDR *, mountbody*);
extern  uint32_t zdr_groups (ZDR *, groups*);
extern  uint32_t zdr_groupnode (ZDR *, groupnode*);
extern  uint32_t zdr_exports (ZDR *, exports*);
extern  uint32_t zdr_exportnode (ZDR *, exportnode*);
extern  uint32_t zdr_mountres3_ok (ZDR *, mountres3_ok*);
extern  uint32_t zdr_mountres3 (ZDR *, mountres3*);
extern  uint32_t zdr_mountstat1 (ZDR *, mountstat1*);
extern  uint32_t zdr_fhandle1 (ZDR *, fhandle1);
extern  uint32_t zdr_mountres1_ok (ZDR *, mountres1_ok*);
extern  uint32_t zdr_mountres1 (ZDR *, mountres1*);

#else /* K&R C */
extern uint32_t zdr_fhandle3 ();
extern uint32_t zdr_dirpath ();
extern uint32_t zdr_name ();
extern uint32_t zdr_mountstat3 ();
extern uint32_t zdr_mountlist ();
extern uint32_t zdr_mountbody ();
extern uint32_t zdr_groups ();
extern uint32_t zdr_groupnode ();
extern uint32_t zdr_exports ();
extern uint32_t zdr_exportnode ();
extern uint32_t zdr_mountres3_ok ();
extern uint32_t zdr_mountres3 ();
extern uint32_t zdr_mountstat1 ();
extern uint32_t zdr_fhandle1 ();
extern uint32_t zdr_mountres1_ok ();
extern uint32_t zdr_mountres1 ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MOUNT_H_RPCGEN */
