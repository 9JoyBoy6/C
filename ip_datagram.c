
#define IP_MAXPACKET 65535 // taille max datagramme IP

struct ip {

  u_char ip_v:4;
  u_char ip_hl:4;
  u_char ip_tos_prio:3;
  u_char ip_tos_quick:1;
  u_char ip_tos_hight_rate:1;
  u_char ip_tos_reliable:1;
  u_char ip_tos_prio_unused:2;
  short ip_len;
  short ip_id;
  ushort ip_off:3;


  ushort ip_offset_fragment:13;
  char ip_ttl;                       // temps à vivre
  char ip_proto;
  short ip_sum;
  Ipadr ip_addr_src;
  Ipadr ip_addr_dst;
  char ip_data[1];                    //donnée(s)

};


// structure udp

struct udp {

  u_short udp_sport; // port source
  u_short udp_dport; // port de destination 
  u_short udp_sum; // somme de contrôle udp
  char udp_data[1]; // donnée(s)

};

// segment tcp

struct tcp {

  u_short th_sport;
  u_short th_dport;
  tcp_seq th_seq;
  tcp_seq th_ack;
  u_char th_off:4;

  u_char th_x2:4;
  u_char th_flags,
  
  #define TH_FIN  0xO1       // indication de fin
  #define TH_SYN  0x02
  #define TH_RST  0x04
  #define TH_PUSH 0x08
  #define TH_ACK  0x10
  #define TH_URG  0x20
  
  u_short th_win;            // taille de fenêtre
  u_short th_sum;
  u_short th_urp;            // pointeur urgent

};
