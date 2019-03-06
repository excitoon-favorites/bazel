def _force_static_impl(ctx):
    outputs = depset()
    for dep in ctx.attr.deps:
        outputs += dep.cc.libs
        outputs += dep.cc.transitive_headers
    return DefaultInfo(files=outputs)

_force_static = rule(
    implementation = _force_static_impl,
    attrs = {
        "deps": attr.label_list(allow_files=True)
    }
)

def force_static(**kwargs):
    _force_static(**kwargs)
    native.cc_library(
        name = "wrapper" + kwargs["name"],
        srcs = [kwargs["name"]],
        linkstatic = 1,
    )
    return ["wrapper" + kwargs["name"]]
