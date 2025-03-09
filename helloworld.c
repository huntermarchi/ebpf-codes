#include <uapi/linux/ptrace.h>
#include <linux/sched.h>

SEC("tracepoint/sched/sched_process_exec")
int hello_world(struct trace_event_raw_sched_process_exec *ctx) {
    bpf_printk("Hello World! Process: %s (PID: %d)\n", ctx->comm, ctx->pid);
    return 0;
}

char _license[] SEC("license") = "GPL";
