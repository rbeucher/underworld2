import os
from config import Package

class libm(Package):

    def gen_locations(self):
        if 'CONDA_DEFAULT_ENV' in os.environ:
            conda_env = os.environ['PREFIX']
            conda_env = os.path.join(conda_env, 'x86_64-conda-linux-gnu/sysroot')
            libpath = os.path.join(conda_env,'lib')
            yield (conda_env, [], [libpath])
        else:
            yield ('/usr/local', ['/usr/local'], ['/usr/local'])


    def gen_envs(self, loc):
        for env in Package.gen_envs(self, loc):
            self.headers = ['math.h']
            if self.find_libraries(loc[2], 'm-2.12'):
                env.PrependUnique(LIBS=['m-2.12'])
                yield env
