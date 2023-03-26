{
    "targets": [
        {
            "target_name": "NtosJS",
            "sources": [
                "ntosjs.cc",
                "cryptojs.cc"
            ],
            "libraries": [
                "-l:libcryptopp.a",
            ],
            "library_dirs": [
                "<(module_root_dir)/cryptopp/",
            ],
            "include_dirs": ["./cryptopp"],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions", "-fno-rtti"],
            "cflags_cc+": ["-frtti"],
        }
    ]
}
