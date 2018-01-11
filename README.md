KeepAwake
=========

This small console program is desgined to be run when you want Windows to not go to sleep on its own.
It's ideal for running long tasks that you want to complete without being interupted by going into standby or hiberating.
This program uses the [recommended public API](https://msdn.microsoft.com/en-us/library/windows/desktop/aa373208%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396) to accomplish it's job.
If you are the author of a long running program, you should use the same API instead of relying on an external program.
This program is intended to be used in conjunction with long running scripts or other programs that don't provide an option to block standby directly.
