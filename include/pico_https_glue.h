/* 
 * Glue HTTP and SSL/TLS libs together
 */

#ifndef PICO_HTTPS_GLUE_H_
#define PICO_HTTPS_GLUE_H_

#include "pico_https_server.h"
#include "pico_stack.h"
#include "pico_tcp.h"
#include "pico_tree.h"
#include "wolfssl/ssl.h"

// Function bindings for wolfSSL
#define SSL_CONTEXT     WOLFSSL
#define SSL_WRITE       wolfSSL_write
#define SSL_READ        wolfSSL_read
int SSL_HANDSHAKE(WOLFSSL* ssl); // We need to tweak retvals, can't directly map
#define SSL_FREE        wolfSSL_free
#define SSL_SHUTDOWN    wolfSSL_shutdown

// Callback signatures specific to wolfSSL
int pico_wolfssl_recv(WOLFSSL *ssl, char *buf, int sz, void *ctx);
int pico_wolfssl_send(WOLFSSL *ssl, char *buf, int sz, void *ctx);


// General setup (initialize entropy, load certs, called ONCE)
int pico_https_ssl_init(
#ifndef USE_TLS_PSK
	const unsigned char* certificate_buffer,
	const unsigned int   certificate_buffer_size,
  const unsigned char* privkey_buffer,
	const unsigned int   privkey_buffer_size
#endif
);


WOLFSSL_CTX *get_wolfSSL_ctx();
// Connection setup (create context, bind socket, set callbacks, once PER CONNECTION)
SSL_CONTEXT* pico_https_ssl_accept(struct pico_socket* sock);  

#endif
