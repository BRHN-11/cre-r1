DIST_SUBDIRS = secp256k1
AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)


if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

COWRIE_CONFIG_INCLUDES=-I$(builddir)/config
COWRIE_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

COWRIE_INCLUDES += -I$(srcdir)/secp256k1/include

LIBCOWRIE_SERVER=libcowrie_server.a
LIBCOWRIE_WALLET=libcowrie_wallet.a
LIBCOWRIE_COMMON=libcowrie_common.a
LIBCOWRIE_CLI=libcowrie_cli.a
LIBCOWRIE_UTIL=libcowrie_util.a
LIBCOWRIE_CRYPTO=crypto/libcowrie_crypto.a
LIBCOWRIE_UNIVALUE=univalue/libcowrie_univalue.a
LIBCOWRIEQT=qt/libcowrieqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES = \
  crypto/libcowrie_crypto.a \
  libcowrie_util.a \
  libcowrie_common.a \
  univalue/libcowrie_univalue.a \
  libcowrie_server.a \
  libcowrie_cli.a
if ENABLE_WALLET
COWRIE_INCLUDES += $(BDB_CPPFLAGS)
EXTRA_LIBRARIES += libcowrie_wallet.a
endif

if BUILD_COWRIE_LIBS
lib_LTLIBRARIES = libcowrieconsensus.la
LIBCOWRIE_CONSENSUS=libcowrieconsensus.la
else
LIBCOWRIE_CONSENSUS=
endif

bin_PROGRAMS =
TESTS =

if BUILD_COWRIED
  bin_PROGRAMS += cowried
endif

if BUILD_COWRIE_UTILS
  bin_PROGRAMS += cowrie-cli cowrie-tx
endif

.PHONY: FORCE
# cowrie core #
COWRIE_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  amount.h \
  base58.h \
  bloom.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  compressor.h \
  primitives/block.h \
  primitives/transaction.h \
  core_io.h \
  crypter.h \
  db.h \
  eccryptoverify.h \
  ecwrapper.h \
  hash.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  merkleblock.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  pow.h \
  protocol.h \
  pubkey.h \
  random.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script/interpreter.h \
  script/script.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  script/script_error.h \
  serialize.h \
  streams.h \
  sync.h \
  threadsafety.h \
  timedata.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  undo.h \
  util.h \
  utilstrencodings.h \
  utilmoneystr.h \
  utiltime.h \
  version.h \
  wallet.h \
  wallet_ismine.h \
  walletdb.h \
  compat/sanity.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libcowrie_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between cowried and cowrie-qt
libcowrie_server_a_CPPFLAGS = $(COWRIE_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libcowrie_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  bloom.cpp \
  chain.cpp \
  checkpoints.cpp \
  init.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  pow.cpp \
  rest.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  script/sigcache.cpp \
  timedata.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(COWRIE_CORE_H)

# wallet: shared between cowried and cowrie-qt, but only linked
# when wallet enabled
libcowrie_wallet_a_CPPFLAGS = $(COWRIE_INCLUDES)
libcowrie_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  wallet_ismine.cpp \
  walletdb.cpp \
  $(COWRIE_CORE_H)

# crypto primitives library
crypto_libcowrie_crypto_a_CPPFLAGS = $(COWRIE_CONFIG_INCLUDES)
crypto_libcowrie_crypto_a_SOURCES = \
  crypto/sha1.cpp \
  crypto/sha256.cpp \
  crypto/sha512.cpp \
  crypto/hmac_sha256.cpp \
  crypto/rfc6979_hmac_sha256.cpp \
  crypto/hmac_sha512.cpp \
  crypto/scrypt.cpp \
  crypto/ripemd160.cpp \
  crypto/common.h \
  crypto/sha256.h \
  crypto/sha512.h \
  crypto/hmac_sha256.h \
  crypto/rfc6979_hmac_sha256.h \
  crypto/hmac_sha512.h \
  crypto/scrypt.h \
  crypto/sha1.h \
  crypto/ripemd160.h

# univalue JSON library
univalue_libcowrie_univalue_a_SOURCES = \
  univalue/univalue.cpp \
  univalue/univalue_read.cpp \
  univalue/univalue_write.cpp \
  univalue/univalue_escapes.h \
  univalue/univalue.h

# common: shared between cowried, and cowrie-qt and non-server tools
libcowrie_common_a_CPPFLAGS = $(COWRIE_INCLUDES)
libcowrie_common_a_SOURCES = \
  allocators.cpp \
  amount.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  primitives/block.cpp \
  primitives/transaction.cpp \
  core_read.cpp \
  core_write.cpp \
  eccryptoverify.cpp \
  ecwrapper.cpp \
  hash.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  pubkey.cpp \
  script/interpreter.cpp \
  script/script.cpp \
  script/sign.cpp \
  script/standard.cpp \
  script/script_error.cpp \
  $(COWRIE_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libcowrie_util_a_CPPFLAGS = $(COWRIE_INCLUDES)
libcowrie_util_a_SOURCES = \
  compat/strnlen.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  random.cpp \
  rpcprotocol.cpp \
  sync.cpp \
  uint256.cpp \
  util.cpp \
  utilstrencodings.cpp \
  utilmoneystr.cpp \
  utiltime.cpp \
  $(COWRIE_CORE_H)

if GLIBC_BACK_COMPAT
libcowrie_util_a_SOURCES += compat/glibc_compat.cpp
libcowrie_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between cowrie-cli and cowrie-qt
libcowrie_cli_a_CPPFLAGS = $(COWRIE_INCLUDES)
libcowrie_cli_a_SOURCES = \
  rpcclient.cpp \
  $(COWRIE_CORE_H)

nodist_libcowrie_util_a_SOURCES = $(srcdir)/obj/build.h
#

# cowried binary #
cowried_LDADD = \
  $(LIBCOWRIE_SERVER) \
  $(LIBCOWRIE_COMMON) \
  $(LIBCOWRIE_UNIVALUE) \
  $(LIBCOWRIE_UTIL) \
  $(LIBCOWRIE_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

if ENABLE_WALLET
cowried_LDADD += libcowrie_wallet.a
endif
cowried_SOURCES = cowried.cpp
#

if TARGET_WINDOWS
cowried_SOURCES += cowried-res.rc
endif

cowried_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
cowried_CPPFLAGS = $(COWRIE_INCLUDES)
cowried_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

# cowrie-cli binary #
cowrie_cli_LDADD = \
  $(LIBCOWRIE_CLI) \
  $(LIBCOWRIE_UTIL) \
  $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)

cowrie_cli_SOURCES = \
  cowrie-cli.cpp

cowrie_cli_CPPFLAGS = $(COWRIE_INCLUDES)
#

# cowrie-tx binary #
cowrie_tx_LDADD = \
  $(LIBCOWRIE_UNIVALUE) \
  $(LIBCOWRIE_COMMON) \
  $(LIBCOWRIE_UTIL) \
  $(LIBCOWRIE_CRYPTO) \
  $(LIBSECP256K1) \
  $(BOOST_LIBS) \
  $(CRYPTO_LIBS)

cowrie_tx_SOURCES = cowrie-tx.cpp
cowrie_tx_CPPFLAGS = $(COWRIE_INCLUDES)
#
cowrie_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
cowrie_cli_SOURCES += cowrie-cli-res.rc
endif
cowrie_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if BUILD_COWRIE_LIBS
include_HEADERS = script/cowrieconsensus.h
libcowrieconsensus_la_SOURCES = \
  primitives/transaction.cpp \
  crypto/hmac_sha512.cpp \
  crypto/scrypt.cpp \
  crypto/sha1.cpp \
  crypto/sha256.cpp \
  crypto/sha512.cpp \
  crypto/ripemd160.cpp \
  eccryptoverify.cpp \
  ecwrapper.cpp \
  hash.cpp \
  pubkey.cpp \
  script/script.cpp \
  script/interpreter.cpp \
  script/cowrieconsensus.cpp \
  uint256.cpp \
  utilstrencodings.cpp

if GLIBC_BACK_COMPAT
  libcowrieconsensus_la_SOURCES += compat/glibc_compat.cpp
  libcowrieconsensus_la_SOURCES += compat/glibcxx_compat.cpp
endif

libcowrieconsensus_la_LDFLAGS = -no-undefined $(RELDFLAGS)
libcowrieconsensus_la_LIBADD = $(CRYPTO_LIBS)
libcowrieconsensus_la_CPPFLAGS = $(CRYPTO_CFLAGS) -I$(builddir)/obj -DBUILD_COWRIE_INTERNAL
if USE_LIBSECP256K1
libcowrieconsensus_la_LIBADD += secp256k1/libsecp256k1.la
endif
endif

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb

clean-local:
	-$(MAKE) -C leveldb clean
	-$(MAKE) -C secp256k1 clean
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
