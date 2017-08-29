#ifndef _XTUN_H
#define _XTUN_H

#include <stdint.h>
#include <netinet/in.h>

#define xTun_VERSION      "0.5.1"
#define xTun_VER          "xTun/" xTun_VERSION

struct tundev;

#ifdef ANDROID
struct tundev * tun_alloc(void);
int tun_config(struct tundev *tun, const char *ifconf, int fd, int mtu,
               int protocol, int global, int verbose, const char *server,
               int port, const char *dns);
#else
struct tundev * tun_alloc(char *iface, uint32_t queues);
void tun_config(struct tundev *tun, const char *ifconf, int mtu,
                struct sockaddr *addr);
#endif
void tun_free(struct tundev *tun);
int tun_start(struct tundev *tun);
void tun_stop(struct tundev *tun);
int tun_keepalive(struct tundev *tun, int on, unsigned int delay);

#endif // for #ifndef _XTUN_H
