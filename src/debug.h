#ifndef _INCLUDE_DEBUG_H_
#define _INCLUDE_DEBUG_H_

#ifdef USE_DEBUG
 #define DEBUG(format...) g_log(G_LOG_DOMAIN, G_LOG_LEVEL_DEBUG, format)
 #define INFO(format...) g_log(G_LOG_DOMAIN, G_LOG_LEVEL_INFO, format)
#else
 #define DEBUG(format...)
 #define INFO(format...)
#endif

#endif /* _INCLUDE_DEBUG_H_ */
