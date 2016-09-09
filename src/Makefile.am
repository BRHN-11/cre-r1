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

WUZHUCOIN_CONFIG_INCLUDES=-I$(builddir)/config
WUZHUCOIN_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

WUZHUCOIN_INCLUDES += -I$(srcdir)/secp256k1/include

LIBWUZHUCOIN_SERVER=libwuzhucoin_server.a
LIBWUZHUCOIN_WALLET=libwuzhucoin_wallet.a
LIBWUZHUCOIN_COMMON=libwuzhucoin_common.a
LIBWUZHUCOIN_CLI=libwuzhucoin_cli.a
LIBWUZHUCOIN_UTIL=libwuzhucoin_util.a
LIBWUZHUCOIN_CRYPTO=crypto/libwuzhucoin_crypto.a
LIBWUZHUCOIN_UNIVALUE=univalue/libwuzhucoin_univalue.a
LIBWUZHUCOINQT=qt/libwuzhucoinqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES = \
  crypto/libwuzhucoin_crypto.a \
  libwuzhucoin_util.a \
  libwuzhucoin_common.a \
  univalue/libwuzhucoin_univalue.a \
  libwuzhucoin_server.a \
  libwuzhucoin_cli.a
if ENABLE_WALLET
WUZHUCOIN_INCLUDES += $(BDB_CPPFLAGS)
EXTRA_LIBRARIES += libwuzhucoin_wallet.a
endif

if BUILD_WUZHUCOIN_LIBS
lib_LTLIBRARIES = libwuzhucoinconsensus.la
LIBWUZHUCOIN_CONSENSUS=libwuzhucoinconsensus.la
else
LIBWUZHUCOIN_CONSENSUS=
endif

bin_PROGRAMS =
TESTS =

if BUILD_WUZHUCOIND
  bin_PROGRAMS += wuzhucoind
endif

if BUILD_WUZHUCOIN_UTILS
  bin_PROGRAMS += wuzhucoin-cli wuzhucoin-tx
endif

.PHONY: FORCE
# wuzhucoin core #
WUZHUCOIN_CORE_H = \
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
libwuzhucoin_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between wuzhucoind and wuzhucoin-qt
libwuzhucoin_server_a_CPPFLAGS = $(WUZHUCOIN_INCLUDES) $(MINIUPNPC_CPPFLAGS)
libwuzhucoin_server_a_SOURCES = \
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
  $(WUZHUCOIN_CORE_H)

# wallet: shared between wuzhucoind and wuzhucoin-qt, but only linked
# when wallet enabled
libwuzhucoin_wallet_a_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
libwuzhucoin_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  wallet_ismine.cpp \
  walletdb.cpp \
  $(WUZHUCOIN_CORE_H)

# crypto primitives library
crypto_libwuzhucoin_crypto_a_CPPFLAGS = $(WUZHUCOIN_CONFIG_INCLUDES)
crypto_libwuzhucoin_crypto_a_SOURCES = \
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
univalue_libwuzhucoin_univalue_a_SOURCES = \
  univalue/univalue.cpp \
  univalue/univalue_read.cpp \
  univalue/univalue_write.cpp \
  univalue/univalue_escapes.h \
  univalue/univalue.h

# common: shared between wuzhucoind, and wuzhucoin-qt and non-server tools
libwuzhucoin_common_a_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
libwuzhucoin_common_a_SOURCES = \
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
  $(WUZHUCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libwuzhucoin_util_a_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
libwuzhucoin_util_a_SOURCES = \
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
  $(WUZHUCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libwuzhucoin_util_a_SOURCES += compat/glibc_compat.cpp
libwuzhucoin_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between wuzhucoin-cli and wuzhucoin-qt
libwuzhucoin_cli_a_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
libwuzhucoin_cli_a_SOURCES = \
  rpcclient.cpp \
  $(WUZHUCOIN_CORE_H)

nodist_libwuzhucoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# wuzhucoind binary #
wuzhucoind_LDADD = \
  $(LIBWUZHUCOIN_SERVER) \
  $(LIBWUZHUCOIN_COMMON) \
  $(LIBWUZHUCOIN_UNIVALUE) \
  $(LIBWUZHUCOIN_UTIL) \
  $(LIBWUZHUCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

if ENABLE_WALLET
wuzhucoind_LDADD += libwuzhucoin_wallet.a
endif
wuzhucoind_SOURCES = wuzhucoind.cpp
#

if TARGET_WINDOWS
wuzhucoind_SOURCES += wuzhucoind-res.rc
endif

wuzhucoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS)
wuzhucoind_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
wuzhucoind_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

# wuzhucoin-cli binary #
wuzhucoin_cli_LDADD = \
  $(LIBWUZHUCOIN_CLI) \
  $(LIBWUZHUCOIN_UTIL) \
  $(BOOST_LIBS) \
  $(SSL_LIBS) \
  $(CRYPTO_LIBS)

wuzhucoin_cli_SOURCES = \
  wuzhucoin-cli.cpp

wuzhucoin_cli_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
#

# wuzhucoin-tx binary #
wuzhucoin_tx_LDADD = \
  $(LIBWUZHUCOIN_UNIVALUE) \
  $(LIBWUZHUCOIN_COMMON) \
  $(LIBWUZHUCOIN_UTIL) \
  $(LIBWUZHUCOIN_CRYPTO) \
  $(LIBSECP256K1) \
  $(BOOST_LIBS) \
  $(CRYPTO_LIBS)

wuzhucoin_tx_SOURCES = wuzhucoin-tx.cpp
wuzhucoin_tx_CPPFLAGS = $(WUZHUCOIN_INCLUDES)
#
wuzhucoin_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
wuzhucoin_cli_SOURCES += wuzhucoin-cli-res.rc
endif
wuzhucoin_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if BUILD_WUZHUCOIN_LIBS
include_HEADERS = script/wuzhucoinconsensus.h
libwuzhucoinconsensus_la_SOURCES = \
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
  script/wuzhucoinconsensus.cpp \
  uint256.cpp \
  utilstrencodings.cpp

if GLIBC_BACK_COMPAT
  libwuzhucoinconsensus_la_SOURCES += compat/glibc_compat.cpp
  libwuzhucoinconsensus_la_SOURCES += compat/glibcxx_compat.cpp
endif

libwuzhucoinconsensus_la_LDFLAGS = -no-undefined $(RELDFLAGS)
libwuzhucoinconsensus_la_LIBADD = $(CRYPTO_LIBS)
libwuzhucoinconsensus_la_CPPFLAGS = $(CRYPTO_CFLAGS) -I$(builddir)/obj -DBUILD_WUZHUCOIN_INTERNAL
if USE_LIBSECP256K1
libwuzhucoinconsensus_la_LIBADD += secp256k1/libsecp256k1.la
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
