from setuptools import setup

setup(name='dspplot',
      version='0.0.1',
      use_2to3=False,
      author='KFRLIB.COM',
      author_email='info@kfrlib.com',
      maintainer='KFRLIB.COM',
      maintainer_email='info@kfrlib.com',
      url='https://www.kfrlib.com/',
      description="Small python plotting library for DSP purposes",
      long_description="Small python plotting library for DSP purposes",
      classifiers=[
          'Development Status :: 4 - Beta',
          'Programming Language :: Python :: 2',
          'Programming Language :: Python :: 2.7',
          'Programming Language :: Python :: 3',
          'Programming Language :: Python :: 3.4',
          'Programming Language :: Python :: 3.5',
          'Topic :: Scientific/Engineering :: Visualization',
      ],
      license='MIT',
      packages=['dspplot'],
      package_data={'dspplot': []},
      install_requires=['matplotlib', 'numpy', 'scipy'],
      zip_safe=False)
