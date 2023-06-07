DSA(Distrubuted Switch Architecture)




The original philosophy behind this design was to be able to use unmodified Linux 
tools such as bridge, iproute2, ifconfig to work transparently whether they 
configured/queried a switch port network device or a regular network device.

An Ethernet switch typically comprises **multiple front-panel ports** and **one or more CPU or management ports**.
The DSA subsystem currently relies on the presence of a management port connected to an Ethernet controller capable of receiving Ethernet frames from the switch. This is a very common setup for all kinds of Ethernet switches found in Small Home and Office products: routers, gateways, or even top-of-rack switches. This **host Ethernet controller** will be later referred to as "master" and "cpu" in DSA terminology and code.

For each front-panel port, DSA creates specialized network devices which are used as controlling and data-flowing endpoints for use by the Linux networking stack. These specialized network interfaces are referred to as "slave" network interfaces in DSA terminology and code.


The ideal case for using DSA is when an Ethernet switch supports a "switch tag" 
which is a hardware feature making the switch insert a specific tag for each 
Ethernet frame it receives to/from specific ports to help the management 
interface figure out:



The subsystem does support switches not capable of inserting/stripping tags, but
the features might be slightly limited in that case (traffic separation relies 
on Port-based VLAN IDs).

Note that DSA does not currently create network interfaces for the "cpu" and 
"dsa" ports because:

* the "cpu" port is the Ethernet switch facing side of the management controller, 
  and as such, would create a duplication of feature, since you would get two 
  interfaces for the same conduit: master netdev, and "cpu" netdev.

* the "dsa" port(s) are just conduits between two or more switches, and as such 
  cannot really be used as proper network interfaces either, only the downstream,
  or the top-most upstream interface makes sense with that model.




