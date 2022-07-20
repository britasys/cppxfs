#pragma once

#ifndef __H_TTFRMMACRO__
#define __H_TTFRMMACRO__

#define ENC_DATA_BLOCK_STR							8
#define ENC_DATA_BLOCK_BIN							64

#define ASSERTPIMPL_BOOL							if(!this->m_pImpl) return false;
#define ASSERTPIMPL_INT								if(!this->m_pImpl) return -1;
#define ASSERTPIMPL_VOID							if(!this->m_pImpl) return;
#define ASSERTPIMPL_NULL							if(!this->m_pImpl) return NULL;

#define ASSERTINITIALIZED_BOOL						if(!this->m_bInitialized)	{ WARNLOG("FAILED because the module is not Initialized") return false; }
#define ASSERTINITIALIZED_INT						if(!this->m_bInitialized)	{ WARNLOG("FAILED because the module is not Initialized") return -1; }
#define ASSERTINITIALIZED_NULL						if(!this->m_bInitialized)	{ WARNLOG("FAILED because the module is not Initialized") return NULL; }
#define ASSERTINITIALIZED_VOID						if(!this->m_bInitialized)	{ WARNLOG("FAILED because the module is not Initialized") return; }

#define TTFRM_LOCK									std::lock_guard<std::mutex>lock(this->m_mutex);

#endif //!__H_TTFRMMACRO__			