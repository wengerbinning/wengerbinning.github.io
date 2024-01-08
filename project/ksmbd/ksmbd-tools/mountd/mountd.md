




```
main -> manager_process_init
main -> manager_systemd_service
```


```
manager_systemd_service -> start_worker_process -> fork -> manager_process_init
manager_systemd_service -> start_worker_process -> fork -> return
```


```
manager_process_init -> generate_sub_auth
manager_process_init -> start_worker_process -> fork -> worker_process_init
manager_process_init -> start_worker_process -> fork -> waitpid
```


```
worker_process_init -> usm_init
worker_process_init -> parse_configs
worker_process_init -> sm_init
worker_process_init -> wp_init
worker_process_init -> rpc_init
worker_process_init -> ipc_init
worker_process_init -> spnego_init
worker_process_init -> ipc_process_event
```