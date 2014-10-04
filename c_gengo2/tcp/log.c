execve("./serveur111", ["./serveur111", "192.168.0.176"], [/* 19 vars */]) = 0
brk(0)                                  = 0x808c000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap2(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb776a000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=112521, ...}) = 0
mmap2(NULL, 112521, PROT_READ, MAP_PRIVATE, 3, 0) = 0xb774e000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/i386-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\1\1\1\0\0\0\0\0\0\0\0\0\3\0\3\0\1\0\0\0000\226\1\0004\0\0\0"..., 512) = 512
fstat64(3, {st_mode=S_IFREG|0755, st_size=1734120, ...}) = 0
mmap2(NULL, 1743580, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xb75a4000
mmap2(0xb7748000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a4) = 0xb7748000
mmap2(0xb774b000, 10972, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xb774b000
close(3)                                = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb75a3000
set_thread_area({entry_number:-1 -> 6, base_addr:0xb75a3900, limit:1048575, seg_32bit:1, contents:0, read_exec_only:0, limit_in_pages:1, seg_not_present:0, useable:1}) = 0
mprotect(0xb7748000, 8192, PROT_READ)   = 0
mprotect(0x8049000, 4096, PROT_READ)    = 0
mprotect(0xb778d000, 4096, PROT_READ)   = 0
munmap(0xb774e000, 112521)              = 0
socket(PF_INET, SOCK_STREAM, IPPROTO_IP) = 3
connect(3, {sa_family=0x7225 /* AF_??? */, sa_data="]\267\200\302w\267\0\0\0\0009\210\4\10"}, 16) = -1 EAFNOSUPPORT (Address family not supported by protocol)
fstat64(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 8), ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb7769000
read(0, "e\n", 1024)                    = 2
sendto(3, "e\n", 2, 0, {sa_family=0x7225 /* AF_??? */, sa_data="]\267\200\302w\267\0\0\0\0009\210\4\10"}, 16) = -1 EPIPE (Broken pipe)
--- SIGPIPE (Broken pipe) @ 0 (0) ---
+++ killed by SIGPIPE +++
